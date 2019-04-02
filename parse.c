/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:32:39 by mqian             #+#    #+#             */
/*   Updated: 2019/04/01 19:59:32 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** piece parser has two parts, the actual parser which takes reads in the
** values and checks for bad input, and the second portion of the function
** which assesses the validity of each piece after its been stored into an
** array which holds all the pieces.
*/


int		piece_reader(char **pieces, int fd, int *pc) //only reads and stores functions from input
{
	int ret;
	int linecount;
	char *temp;
	char *line;

	linecount = 0;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (ft_strlen(line) != 4 && linecount < 4) //remove these lines later or put check somewhere else?
			return (0);
		if (linecount++ < 4)
		{
			if (!pieces[*pc])
				pieces[*pc] = ft_strnew(0);
			temp = ft_strjoin(pieces[*pc], line);
			ft_memdel((void **)&pieces[*pc]);
			pieces[*pc] = temp;
		}
		else //linecount is "==" 5 its on 5th empty line, but value is still technically 4
		{
			if (ft_strlen(line) != 0)
				return (0);
			linecount = 0;
			*pc = *pc + 1; //don't process the empty line
		}
	}
	return ((ret < 0 || *pc > 26) ? 0 : 1);
}

int		is_valid_input(char **pieces, int *pc) // check number of "#", "." in each file
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
		{
			ft_putstr("incorrect input\n");
			return (0);
		}
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
		{
			ft_putstr("invalid piece\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int		parse_and_retrieve(char **pieces, int fd) //struct tetrimino *peaces
{
	int ret;
	int piececount;

	piececount = 0;
	if (!(ret = piece_reader(&*pieces, fd, &piececount)))
	{
		ft_putstr("piece_reader failed\n");
		return (0);
	}
	if (!(ret = is_valid_input(&*pieces, &piececount)))
	{
		ft_putstr("is_valid_input failed\n");
		return (0);
	}
	if (!(ret = is_valid_piece(&*pieces, &piececount)))
	{
		ft_putstr("is_valid_piece failed\n");
		return (0);
	}
	return (1);
}