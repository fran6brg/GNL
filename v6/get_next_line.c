/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 23:45:15 by fberger           #+#    #+#             */
/*   Updated: 2019/01/15 02:27:43 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					reach_nl_eof(int fd, char **str, char **buf)
{
	int				ret;
	int				i;
	char			*ptr; // ?

	i = 0;
	while ((ret = read(fd, *buf, BUFF_SIZE)) > 0)
	{
		(*buf)[ret] = '\0';
		ptr = *str;
		if (*str)
		 		*str = ft_strjoin(*str, *buf);
		else
				*str = ft_strdup(*buf);
		if (i >= 1)
				ft_strdel((void *)&ptr); // ?
		i++;
		if (ft_strchr(*str, '\n'))
		{
			ft_memdel((void *)buf);
			return (ret);
		}
	}
	ft_memdel((void *)buf);
	if (i == 0 && ret == 0 && !*str)
			return (-1);
	return (ret);
}

int					cp_str_in_line(char **line, char **str, int *ret1)
{
	int				i;
	char			*ptr;

	ptr = *str;
	i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (i == 0 || ptr[0] == '\0')
	{
		if (!(*line = ft_strnew(0))) // auparavant = ft_strdup("")))
				return (-1);
	}
	else if (!(*line = ft_strsub(ptr, 0, i)))
		return (-1);
	if (!ft_strlen(*str) && *ret1 == 0)
		return (0);
	if (i >= (int)ft_strlen(*str))
			ft_strclr(*str); // ne pas changer car bloque le multi
	else
		*str += (i + 1);
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*str[10000] = {NULL};
	int				ret1;
	char			*buf;
	int				ret2;

	if (!line || fd < 0 || !(buf = (char *)ft_memalloc(BUFF_SIZE + 1)))
			return (-1);
	if ((ret1 = reach_nl_eof(fd, &str[fd], &buf) == -1))
			return (-1);
	ret2 = cp_str_in_line(line, &str[fd], &ret1);
	return (ret2);
}
