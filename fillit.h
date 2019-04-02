/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:59:41 by mqian             #+#    #+#             */
/*   Updated: 2019/04/01 17:33:44 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include "get_next_line.h"

/*
typedef struct block
{
	int up;
	int down;
	int left;
	int right;
	int x;
	int y;
};

typedef struct tetrimino
{
	block one;
	block two;
	block three;
	block four;
};
*/

int		parse_and_retrieve(char **pieces, int fd);//, struct tetrimino *peaces);
int		piece_reader(char **pieces, int fd, int *pc);
int		is_valid_input(char **pieces, int *pc);
int		is_valid_piece(char **pieces, int *pc);
void	solver(char **pieces);
void	check_adjacent(char **pieces, int *i, int *j, int *borders);

#endif