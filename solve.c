/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:59:24 by mqian             #+#    #+#             */
/*   Updated: 2019/04/03 20:04:54 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //delete this line later

int		*encode_index(char *piece)
{
	int *encoded;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(encoded = (int *)malloc(sizeof(int) * 4)))
		return (0);
	while (i < 16)
	{
		if (piece[i] != '.')
		{
			encoded[j++] = i;
		}
		i++;
	}
	return (encoded);
}

void	place_piece(char **map, char *piece, int x, int y)
{
	int size;
	int j;
	int i;
	int *hold;
	char c;

	i = 0;
	while (i < 16)
	{
		if (piece[i] != '.')
		{
			c = piece[i];
			break;
		}
		i++;
	}
	hold = encode_index(piece);
	size = get_map_size(&*map);
	j = 0;
	while (j < 4)
	{
		map[y + (hold[j] / 4)][x + (hold[j] % 4)] = c; //map[testing y pos + (abstracted y pos from left/top justified string)]
		j++;
	}
	ft_memdel(&hold);
}

int		place_validate(char **map, char *piece, int x, int y)
{
	int *hold;
	int i;
	int p_x;
	int p_y;
	int len;

	i = 0;
	len = get_map_size(&*map);
	if (!(hold = encode_index(piece)))
		return (0);
	while (i < 4)
	{
		p_x = y + (hold[i] % 4);
		p_y = y + (hold[i] / 4);
		if (p_x + x >= len || p_y + y >= len || map[p_y + y][p_x + x] != '.')
			return (0);
		i++;
	}
	return (1);
}


void	solver(char **pieces)
{
	char **map; //set up map for first time, then start recursive solving function?
	int numpieces;
	int size;

	numpieces = 0;
	while (pieces[numpieces]) //dont know if this is needed;
		numpieces++;
	size = set_map_size(numpieces);
	if (!(map = generate_map(size)))
		return ;
	while (!solver_recursive(&*pieces, &*map)
	{
		map = resize_map(&*map);
	}
}
