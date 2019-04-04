/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:26:41 by mqian             #+#    #+#             */
/*   Updated: 2019/04/03 20:03:59 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //delete this line later


int		get_map_size(char **map)
{
	int len;

	len = 0;
	while (map[0][len])
		len++;
	return (len);
}

char **		generate_map(int size)
{
	char *rows;
	char **columns;
	int i;
	int j;

	i = 0;
	if (!(columns = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	columns[size] = 0; //zero last block of column
	while (i < size)
	{
		j = 0;
		if (!(columns[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		columns[i][size] = '\0';
		while (j < size) //populate to empty map
			columns[i++][j++] = '.';
	}
	return (columns);
}

void		free_map(char **map)
{
	int len;

	len = get_map_size(&*map);
	while (i < len)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

char **		copy_map(char **map, int size)
{
	int i; // row
	int j; // column
	char **new;

	i = 0;
	if (!(new = generate_map(size + 1)))
		return (NULL);
	while (map[i]) // will terminate when it hits zeroed block
	{
		j = 0;
		while (map[i][j]) //will terminate when it hits null terminator
		{
			new[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	free_map(&*map);
	return (new);
}

int		set_map_size(int numblocks)
{
	int total;
	int n;

	n = 0;
	total = 4 * numblocks;
	while (n * n < total)
	{
		n++;
	}
	return (n);
}

char **		resize_map(char **map)
{
	int i; // row
	int j; // column
	char **new;

	i = 0;
	if (!(new = generate_map(get_map_size(&*map) + 1)))
		return (NULL);
	free_map(&*map);
	map = new;
	return (map);
}