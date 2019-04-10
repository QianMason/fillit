/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:35:41 by mqian             #+#    #+#             */
/*   Updated: 2019/04/09 20:11:45 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

/*
** this .c will be the main func
*/

void	print_pieces(char *pieces[])
{
	int i = 0;
	while (pieces[i])
	{
		int j = 0;
		ft_putchar('\n');
		while (j < 16)
		{
			if (j == 4 || j == 8 || j == 12)
				ft_putchar('\n');
			ft_putchar(pieces[i][j]);
			j++;
		}
		if (j == 16)
			ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	char *pieces[27];
	int ret;
	int fd;
	int zero;

	zero = 26;
	while (zero >= 0) //zero all blocks so i have enough lines in piece_reader to check for line length
		pieces[zero--] = 0;
	ret = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 3 ||
		!(ret = parse_and_retrieve(&*pieces, fd)))
	{
		ft_putstr("error\n");
		return (0);
	}
	solver(&*pieces);
	return (0);
}
