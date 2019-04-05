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
	if (!(encoded = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	//printf("place_piece func777\n");
	while (i < 16)
	{
		//printf("place_piece func99\n");
		if (piece[i] != '.')
		{
			//printf("place_piece func100\n");
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
	//ft_memdel((void**)&hold);
}

int		place_validate(char ***map, char **pieces, int piecenum, int x, int y)
{
	int *hold;
	int i;
	int p_x;
	int p_y;
	int len;
	printf("value of x: %d\n", x);
	printf("vlaue of y: %d\n", y);
	i = 0;
	len = get_map_size(*map);
	printf("value of len: %d\n", len);
	if (piecenum == 0) //might need to change this
		return (1);
	if (!(hold = encode_index(pieces[piecenum])))// #ISOLATED THE FUCKING ISSUE:??????
		return (0);
	else
	{
		while (i < 4)
		{
			p_x = x + (hold[i] % 4);
			p_y = y + (hold[i] / 4);
			printf("p_x is = %d\n", p_x);
			printf("p_y is = %d\n", p_y);
			if (p_x >= len || p_y>= len || *map[p_y][p_x] != '.'|| *map[p_y][p_x] != (char)((piecenum - 1) + 65))
				return (0);

			i++;

		}
	}

	return (1);
}


int		solver_recursive(char **map, char **pieces, int piecenum, int numpieces)
{
	int x;
	int y;

	y = 0;
	printf("recursive call\n");
	if (piecenum == numpieces)
		return (1);
	if (get_map_size(&*map) > 6)
	{
		printf("map size is %d\n", get_map_size(&*map));
		return (1);
	}
	while (y < get_map_size(&*map))
	{
		x = 0;
		while (x < get_map_size(&*map))
		{
			printf("got in here???????????????????????????????????????????????????\n");
			if (place_validate(&map, &*pieces, piecenum, x, y))
			{
				place_piece(&*map, pieces[piecenum], x, y);
				print_map(&*map);
				printf("returning recursive call\n");
				return (solver_recursive(&*map, &*pieces, piecenum + 1, numpieces));
			}
			x++;
		}
		y++;
	}
	return (0);
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
	while (!solver_recursive(&*map, &*pieces, 0, numpieces))
	{
		map = resize_map(&*map);
	}
	print_map(&*map);
}

void print_map(char **map) //DELETE THIS FUNCTION
{
	int i;
	int j;

	i = 0;
	j = get_map_size(&*map);
	while (i < j)
	{
		printf("%s\n", map[i]);
		i++;
	}
}
