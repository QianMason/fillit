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

int		parse_and_retrieve(char **pieces, int fd); //21 lines
int		piece_reader(char **pieces, int fd, int *pc); //27 lines
int		is_valid_input(char **pieces, int *pc); //27 lines
int		is_valid_piece(char **pieces, int *pc); //24 lines
void	top_left_justify(char **pieces); //19 lines

/*
*** parse_helpers.c
*/
int		check_operation(int **values, int direction); //22 lines
void	check_adjacent(char **pieces, int *i, int *j, int *borders); //11 lines
void	top_left_helper_helper(int **values, int op, int i); //24 lines
void	top_left_helper(int *values, char *pieces, int k); //13 lines

/*
*** solve.c
*/

int		*encode_index(char *piece); //16 lines
void	place_piece(char **map, char *piece, int x, int y); //25 lines
int		place_validate(char **map, char **pieces, int piecenum, int x, int y); //23 lines but too many parameters
int		solver_recursive(char **map, char **piece, int piecenum, int numpieces); //25 lines, 24 without print function
void	solver(char **pieces); //14 lines, 13 without print function

/*
*** map.c
*/

int		get_map_size(char **map);
char	**generate_map(int size);
void	free_map(char **map);
int		set_map_size(int numblocks);
char	**resize_map(char **map);

void	print_map(char **map);
void	remove_pieces(char **map, char c); //18 lines
#endif
