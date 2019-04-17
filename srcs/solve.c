/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:59:24 by mqian             #+#    #+#             */
/*   Updated: 2019/04/16 20:10:56 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		*encode_index(char *piece)
{
	int *encoded;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(encoded = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	while (i < 16)
	{
		if (piece[i] != '.')
			encoded[j++] = i;
		i++;
	}
	return (encoded);
}

void	place_piece(char **map, char *piece, int x, int y)
{
	int		size;
	int		j;
	int		i;
	int		*hold;
	char	c;

	i = 0;
	while (i < 16)
	{
		if (piece[i] != '.')
		{
			c = piece[i];
			break ;
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
	ft_memdel((void**)&hold);
}

int		place_validate(char **map, char **pieces, int piecenum, int arr[])
{
	int *hold;

	if (!(hold = encode_index(pieces[piecenum])))
		return (0);
	else
	{
		if (!place_validate_helper(map, piecenum, hold, arr))
			return (0);
	}
	ft_memdel((void**)&hold);
	return (1);
}

int		solver_recursive(char **map, char **pieces, int piecenum, int numpieces)
{
	int x_y[2];

	array_zero(x_y);
	if (piecenum == numpieces)
		return (1);
	while (x_y[1] < get_map_size(&*map))
	{
		x_y[0] = 0;
		while (x_y[0] < get_map_size(&*map))
		{
			if (place_validate(&*map, &*pieces, piecenum, x_y))
			{
				place_piece(&*map, pieces[piecenum], x_y[0], x_y[1]);
				if (solver_recursive(&*map, &*pieces, piecenum + 1, numpieces))
					return (1);
				else
					remove_pieces(&*map, (char)(piecenum + 65));
			}
			x_y[0] = x_y[0] + 1;
		}
		x_y[1] = x_y[1] + 1;
	}
	return (0);
}

void	solver(char **pieces)
{
	char	**map;
	int		numpieces;
	int		size;

	numpieces = 0;
	while (pieces[numpieces])
		numpieces++;
	size = set_map_size(numpieces);
	if (!(map = generate_map(size)))
	{
		ft_putendl("error");
		return ;
	}
	while (!solver_recursive(&*map, &*pieces, 0, numpieces))
		map = resize_map(&*map);
	print_map(&*map);
	free_map(&*map);
}
