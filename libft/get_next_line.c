/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:28:57 by mqian             #+#    #+#             */
/*   Updated: 2019/03/25 18:57:35 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ret_string_delim(char *s, char c) //function that returns a portion of the string up to the first delimiter
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_strsub(s, 0, i));
}

char	*ret_remain_line(char *s, char c)
{
	int i;
	int j;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	j = i;
	while (s[i])
	{
		i++;
	}
	if (j == i)
		return (ft_strsub(s, j, 0));
	j++; //since it ended where i ended which is a \n
	return (ft_strsub(s, j, (i - j)));
}

int		read_helper(int ret, char *buff, char **filed, char **line)
{
	char *temp;
	char *temp2;

	buff[ret] = '\0'; // null terminate the end of the read
	if (!*filed) // since it might be the case the buffer read size is less than an actual line, its done in a loop, and we are joining strings together, we have to free the old one so we use temp and do a check
		*filed = ft_strnew(0);
	temp = ft_strjoin(*filed, buff);
	ft_memdel((void **) &*filed);
	*filed = temp;
	if (ft_strchr(*filed, '\n')) //line is found in the buff, extract it and reset, then return 1, if not found return 0, and call read again.
	{
		*line = ret_string_delim(*filed, '\n');
		temp2 = ret_remain_line(*filed, '\n');
		ft_memdel((void **) &*filed);
		*filed = temp2;
		return (1);
	}
	return (0);
}

int		get_remain_lines(char **filed, char **line)
{
	char	*temp;
	char	*temp2;
	int		len;

	len = 0;
	if (ft_strchr(*filed, '\n'))
	{
		temp = ret_string_delim(*filed, '\n');
		temp2 = ret_remain_line(*filed, '\n');
		*line = temp;
		ft_memdel((void **) &*filed);
		*filed = temp2;
		return (1);
	}
	else //last line of the thing
	{
		if (ft_strlen(*filed) > 0)
		{
			*line = ft_strdup(*filed); // PROBLEM WAS HERE, you were doing *line = *filed and then you were freeing *filed
			ft_memdel((void **) &*filed);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*filed[5000]; //ask oscar about this number
	char 		buff[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (read_helper(ret, buff, &filed[fd], &*line))
			break ;
	}
	if (ret == 0 && filed[fd]) //case where you reached the end of a read, but there is still stuff in the buffer
	{
		if (get_remain_lines(&filed[fd], &*line))
			return (1);
		else
			return (0);
	}
	if (ret == 0)
		return (0);
	return ((ret < 0) ? -1 : 1);
}
