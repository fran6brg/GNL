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

static int			cp_str_nl_to_line(char **str, char **line)
{
	int				index;

	index = 0;
	while ((*str)[index] != '\0' && (*str)[index] != '\n')
		index++;
	if (!(*line = ft_strsub(*str, 0, index)))
		return (-1);
	if ((*str)[index] != '\0')
		*str = ft_strcpy(*str, (*str + index) + 1);
	else
		ft_strdel(str);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	static char		*str[10000];

	if (fd < 0 || fd > 10000)
		return (-1);
	if (!line || (!str[fd] && !(str[fd] = ft_strnew(0))))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = str[fd];
		if (!(str[fd] = ft_strjoin(str[fd], buff)))
			return (-1);
		free(tmp);
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
	}
	if (ret <= 0 && !ft_strlen(str[fd]))
		return (ret);
	return (cp_str_nl_to_line(&str[fd], line));
}
