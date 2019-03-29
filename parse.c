/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:32:39 by mqian             #+#    #+#             */
/*   Updated: 2019/03/28 20:47:52 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** piece parser has two parts, the actual parser which takes reads in the
** values and checks for bad input, and the second portion of the function
** which assesses the validity of each piece after its been stored into an
** array which holds all the pieces.
*/


int		piece_reader(**char pieces, int fd, int *pc) //only reads and stores functions from input
{
	int ret;
	int linecount;
	char *temp;
	char *line;

	linecount = 0;
	while (ret = get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != 4) //remove these lines later or put check somewhere else?
			return (0);
		if (linecount++ < 4)
		{
			if (!pieces[*pc])
				pieces[*pc] = ft_strnew(0);
			temp = ft_strjoin(pieces[*pc], line);
			ft_memdel(&pieces[*pc]);
			pieces[*pc] = temp;
		}
		else //count == 5
		{
			count = 0;
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
			return (0);
		i++;
	}
	return (1);
}

int		is_valid_piece(char **pieces, int *pc)
{

}
int		parse_and_retrieve(char **pieces, int fd)
{
	int ret;
	int piececount;

	piececount = 0;
	if (!(ret = piece_parser(&*pieces, fd, &piececount)))
		return (0);
	if (!(ret = is_valid_piece(&*pieces, &piececount)))
		return (0);
	return ()
}