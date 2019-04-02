/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:10:06 by mqian             #+#    #+#             */
/*   Updated: 2019/03/25 19:44:29 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/includes/libft.h"

char	*ret_string_delim(char *s, char c);
char	*ret_remain_line(char *s, char c);
int		read_helper(int ret, char *buff, char **filed, char **line);
int		get_remain_lines(char **filed, char **line);
int		get_next_line(const int fd, char **line);

#endif
