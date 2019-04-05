/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:35:41 by mqian             #+#    #+#             */
/*   Updated: 2019/04/03 20:04:56 by mqian            ###   ########.fr       */
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
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 3)
	{
		ft_putstr("problem opening file\n");
		return (0);
	}
	if (!(ret = parse_and_retrieve(&*pieces, fd))) // will go through source file and parse pieces while checking for bad input, will
	{
		ft_putstr("bad input or reading error or too many pieces!\n");
		return (0);
	}
	solver(&*pieces);
	return (0);
}
