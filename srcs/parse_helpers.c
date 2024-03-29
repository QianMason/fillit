/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:58:37 by mqian             #+#    #+#             */
/*   Updated: 2019/04/16 20:05:43 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	check_adjacent(char **pieces, int *i, int *j, int *borders) //GOOD
{
	if (pieces[*i][*j] == '#')
	{
		if (((*j + 1) % 4 != 0) && (*j + 1) < 16 && pieces[*i][*j + 1] == '#') //so the block check to the right doesnt segfault
			*borders = *borders + 1;
		if ((*j + 4 < 16) && pieces[*i][*j + 4] == '#') // bottom block check
			*borders = *borders + 1;
		if ((*j - 1) % 4 != 3 && (*j - 1) >= 0 && pieces[*i][*j - 1] == '#') // left block check
			*borders = *borders + 1;
		if ((*j - 4 >= 0) && pieces[*i][*j - 4] == '#') // top block check
			*borders = *borders + 1;
	}
}

int		check_operation(int **values, int direction) //1 or 2 based on check left or up //22 lines //GOOD
{
	int i;

	i = 0;
	if (direction == 1)  //left
	{
		while (i < 4)
		{
			if (((*values)[i] % 4) - 1 < 0)
				return (0);
			i++;
		}
	}
	else
	{
		while (i < 4)
		{
			if (((*values)[i] - 4) < 0)
				return (0);
			i++;
		}
	}
	return (1);
}

void top_left_helper_helper(int **values, int op, int i)
{
	if (op == 1)
	{
		while (check_operation(&*values, 1))
		{
			i = 0;
			while (i < 4)
			{
				(*values)[i] = (*values)[i] - 1;
				i++;
			}
		}
	}
	else
	{
		while (check_operation(&*values, 2))
		{
			i = 0;
			while (i < 4)
			{
				(*values)[i] = (*values)[i] - 4;
				i++;
			}
		}
	}
}

void	top_left_helper(int *values, char *pieces, int k)
{
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	a = 0;
	top_left_helper_helper(&values, 1, a);
	top_left_helper_helper(&values, 2, a);
	while (i < 16)
		pieces[i++] = '.';
	while (j < 4)
		pieces[values[j++]] = (char)(k + 65);
}
