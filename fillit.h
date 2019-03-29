/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:59:41 by mqian             #+#    #+#             */
/*   Updated: 2019/03/28 20:47:53 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include "get_next_line/get_next_line.h"

int		parse_and_retrieve(char **pieces, int fd);
int		piece_reader(char **pieces, int fd, int *pc);
int		is_valid_input(char **pieces, int *pc);
void	solver(char **pieces);

