/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:26:41 by mqian             #+#    #+#             */
/*   Updated: 2019/04/09 21:03:07 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h> //delete this line later


int		get_map_size(char **map)
{
	int len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

char **		generate_map(int size)
{
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
			columns[i][j++] = '.';
		i++;
	}
	return (columns);
}

void		free_map(char **map)
{
	int len;
	int i;

	i = 0;
	len = get_map_size(&*map);
	while (i < len)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
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
	char **new;

	if (!(new = generate_map(get_map_size(&*map) + 1)))
		return (NULL);
	free_map(&*map);
	map = new;
	return (map);
}
