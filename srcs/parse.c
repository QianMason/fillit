/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:32:39 by mqian             #+#    #+#             */
/*   Updated: 2019/04/16 20:14:40 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** piece parser has two parts, the actual parser which takes reads in the
** values and checks for bad input, and the second portion of the function
** which assesses the validity of each piece after its been stored into an
** array which holds all the pieces.
*/

int		piece_reader(char **pieces, int fd, int *pc) //only reads and stores functions from input //27 lines
{ //it checks for bad line length, and incorrect number of lines in file
	int		ret;
	int		linecount;
	char	*line;
	int		totalcount;

	linecount = 0;
	totalcount = 0;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (linecount++ < 4)
		{
			piece_reader_helper(&*pieces, &*pc, &line);
			totalcount++;
			if (linecount == 4)
				*pc = *pc + 1;
		}
		else //linecount is "==" 5 its on 5th empty line, but value is still technically 4
		{
			linecount = 0; //don't process empty line
			totalcount++;
		}
	}
	ft_memdel((void**)&line);
	return ((totalcount / 5 != (*pc - 1)) ? 0 : 1);
}

int		is_valid_input(char **pieces, int *pc)
{
	int i;
	int j;
	int dot_hash[2];

	i = 0;
	while (i < *pc)
	{
		array_zero(dot_hash);
		j = 0;
		while (pieces[i][j] != '\0')
		{
			if (pieces[i][j] == '#')
				dot_hash[1]++;
			else if (pieces[i][j] == '.')
				dot_hash[0]++;
			j++;
		}
		if (dot_hash[0] != 12 || dot_hash[1] != 4)
			return (0);
		i++;
	}
	return (1);
}

int		is_valid_piece(char **pieces, int *pc)
{
	int i;
	int j;
	int borders;
	int len;

	i = 0;
	while (i < *pc)
	{
		borders = 0;
		j = 0;
		len = ft_strlen(pieces[i]);
		while (j < len)
		{
			check_adjacent(&*pieces, &i, &j, &borders);
			j++;
		}
		if ((borders / 2) < 3) //a piece aint valid, return 0
			return (0);
		i++;
	}
	return (1);
}

void	top_left_justify(char **pieces) //cycle through validated pieces, and mod index and subtract to 0 to get //GOOD
// left justify, and add +4 to top justify //19 lines
{
	int i;
	int j;
	int count;
	int values[4];

	i = 0;
	while (pieces[i] != 0)
	{
		j = 0;
		count = 0;
		while (pieces[i][j])
		{
			if (pieces[i][j] == '#')
				values[count++] = j;
			j++;
		}
		top_left_helper(values, pieces[i], i);
		i++;
	}
}

int		parse_and_retrieve(char **pieces, int fd)
{
	int ret;
	int piececount;

	piececount = 0;
	if (!(piece_reader(&*pieces, fd, &piececount)))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(ret = is_valid_input(&*pieces, &piececount)))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(ret = is_valid_piece(&*pieces, &piececount)))
	{
		ft_putendl("error");
		return (0);
	}
	top_left_justify(&*pieces);
	return (1);
}
