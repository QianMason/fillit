/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:35:41 by mqian             #+#    #+#             */
/*   Updated: 2019/03/28 20:22:23 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** this .c will be the main func
*/

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
		ft_putstr('usage: ./fillit source_file\n');
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
	{
		ft_pustr("problem opening file\n")
		return (0);
	}
	if (!(ret = retrieve(&*pieces, fd)) // will go through source file and parse pieces while checking for bad input, will
	{
		ft_putstr('bad input or reading error or too many pieces!\n');
		return (0);
	}
	solver(&*pieces);
	return (0);
}