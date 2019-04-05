/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:59:41 by mqian             #+#    #+#             */
/*   Updated: 2019/04/03 16:19:46 by mqian            ###   ########.fr       */
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
*** parse.c
*/

int		parse_and_retrieve(char **pieces, int fd);//, struct tetrimino *peaces);
int		piece_reader(char **pieces, int fd, int *pc);
int		is_valid_input(char **pieces, int *pc);
int		is_valid_piece(char **pieces, int *pc);
void	top_left_justify(char **pieces);

/*
*** parse_helpers.c
*/
int		check_operation(int **values, int direction);
void	check_adjacent(char **pieces, int *i, int *j, int *borders);
void	left_helper(int **values);
void	top_helper(int **values);
void	top_left_helper(int *values, char *pieces, int k);

/*
*** solve.c
*/

int		*encode_index(char *piece);
void	place_piece(char **map, char *piece, int x, int y);
int		place_validate(char ***map, char **pieces, int piecenum, int x, int y);
int		solver_recursive(char **map, char **piece, int piecenum, int numpieces);
void	solver(char **pieces);

/*
*** map.c
*/

int		get_map_size(char **map);
char	**generate_map(int size);
void	free_map(char **map);
int		set_map_size(int numblocks);
char	**resize_map(char **map);

void	print_map(char **map);

#endif
