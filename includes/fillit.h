/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:59:41 by mqian             #+#    #+#             */
/*   Updated: 2019/04/16 20:04:40 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

/*
*** parse.c GOOD
*/

int		parse_and_retrieve(char **pieces, int fd);
int		piece_reader(char **pieces, int fd, int *pc);
int		is_valid_input(char **pieces, int *pc);
int		is_valid_piece(char **pieces, int *pc);
void	top_left_justify(char **pieces);

/*
*** parse_helpers.c GOOD
*/
int		check_operation(int **values, int direction);
void	check_adjacent(char **pieces, int *i, int *j, int *borders);
void	top_left_helper_helper(int **values, int op, int i);
void	top_left_helper(int *values, char *pieces, int k);

/*
*** solve.c GOOD
*/

int		*encode_index(char *piece);
void	place_piece(char **map, char *piece, int x, int y);
int		place_validate(char **map, char **pieces, int piecenum, int arr[]);
int		solver_recursive(char **map, char **piece, int piecenum, int numpieces);
void	solver(char **pieces);

/*
*** map.c GOOD
*/

int		get_map_size(char **map);
char	**generate_map(int size);
void	free_map(char **map);
int		set_map_size(int numblocks);
char	**resize_map(char **map);

/*
*** helpers.c GOOD
*/

void	array_zero(int arr[]);
int		place_validate_helper(char **map, int piecenum, int *hold, int arr[]);
void	print_map(char **map);
void	remove_pieces(char **map, char c);
void	piece_reader_helper(char **pieces, int *pc, char **line);
#endif
