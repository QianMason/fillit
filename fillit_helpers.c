/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:58:37 by mqian             #+#    #+#             */
/*   Updated: 2019/04/01 17:11:36 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_adjacent(char **pieces, int *i, int *j, int *borders)
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