/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:32:39 by mqian             #+#    #+#             */
/*   Updated: 2019/04/09 19:30:12 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h> //remove this later

/*
** piece parser has two parts, the actual parser which takes reads in the
** values and checks for bad input, and the second portion of the function
** which assesses the validity of each piece after its been stored into an
** array which holds all the pieces.
*/

int		piece_reader(char **pieces, int fd, int *pc) //only reads and stores functions from input //27 lines
{ //it checks for bad line length, and incorrect number of lines in file
	int ret;
	int linecount;
	char *temp;
	char *line;
	int totalcount;

	linecount = 0;
	totalcount = 0;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (linecount++ < 4)
		{
			if (!pieces[*pc])
				pieces[*pc] = ft_strnew(0);
			temp = ft_strjoin(pieces[*pc], line); // LEAK HERE?? WTF????????????????????????
			ft_memdel((void**)&pieces[*pc]);
			pieces[*pc] = temp;
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
	if (totalcount / 5 != (*pc - 1))
		return (0);
	return (1);
}

int		is_valid_input(char **pieces, int *pc) // check number of "#", "." in each file //27
{
	int i;
	int j;
	int hash;
	int dot;

	i = 0;
	while (i < *pc)
	{
		dot = 0;
		hash = 0;
		j = 0;
		while (pieces[i][j] != '\0')
		{
			if (pieces[i][j] == '#')
				hash++;
			else if (pieces[i][j] == '.')
				dot++;
			j++;
		}
		if (dot != 12 || hash != 4)
			return (0);
		i++;
	}
	return (1);
}

int		is_valid_piece(char **pieces, int *pc) //24 lines
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

void	top_left_justify(char **pieces) //cycle through validated pieces, and mod index and subtract to 0 to get
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

int		parse_and_retrieve(char **pieces, int fd) //21 lines
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
