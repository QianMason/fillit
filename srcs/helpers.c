/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:43:51 by mqian             #+#    #+#             */
/*   Updated: 2019/04/16 20:09:48 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_map(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	j = get_map_size(&*map);
	while (i < j)
	{
		ft_putendl(map[i]);
		i++;
		count++;
	}
}

void	remove_pieces(char **map, char c)
{
	int len;
	int i;
	int j;

	len = get_map_size(&*map);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	array_zero(int arr[])
{
	arr[0] = 0;
	arr[1] = 0;
}

int		place_validate_helper(char **map, int piecenum, int *hold, int arr[])
{
	int i;
	int len;
	int p_x;
	int p_y;

	i = 0;
	len = get_map_size(map);
	while (i < 4)
	{
		p_x = arr[0] + (hold[i] % 4);
		p_y = arr[1] + (hold[i] / 4);
		if (p_x >= len || p_y >= len || map[p_y][p_x] ==
			(char)((piecenum - 1) + 65) || map[p_y][p_x] != '.')
		{
			ft_memdel((void**)&hold);
			return (0);
		}
		i++;
	}
	return (1);
}

void	piece_reader_helper(char **pieces, int *pc, char **line)
{
	char *temp;

	if (!pieces[*pc])
		pieces[*pc] = ft_strnew(0);
	temp = ft_strjoin(pieces[*pc], *line);
	ft_memdel((void**)&pieces[*pc]);
	pieces[*pc] = temp;
}
