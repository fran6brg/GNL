/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 05:04:09 by araout            #+#    #+#             */
/*   Updated: 2018/11/21 13:42:09 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					reach_nl_or_EOF(int fd, char **str, char **buf)
{
	int				ret;
	int 			i;
	char			*ptr;

	i = 0;
	while ((ret = read(fd, *buf, BUFF_SIZE)) > 0 && ++i)
	{
		ptr = *buf;
		ptr[ret] = '\0';
		ptr = *str;

		*str = (*str ? ft_strjoin(*str, *buf) : ft_strdup(*buf));
		if (i > 1)
			ft_memdel((void *)&ptr);
		if (ft_strchr(*str, '\n'))
		{
			ft_memdel((void *)buf);
			return (ret);
		}
	}
	ft_memdel((void *)buf);
	return (ret);
}

int					cp_str_in_line(char **line, char **str, int *ret1)
{
	int				i;
	char			*ptr;

	ptr = *str;
	i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n') // read
		i++;
	if (i == 0 || ptr[0] == '\0') // 1.a si str est vide alors copier "" dans line
	{
		if (!(*line = ft_strdup(""))) // si fail strdup
			return (-1);
	}
	else if (!(*line = ft_strsub(ptr, 0, i))) // 1.b sinon si !vide remplir line
		return (-1);
	if (!ft_strlen(*str) && *ret1 == 0) // 2.a si str est vide et EOF
		return (0); // 2.b fin du game
	if (i >= (int)ft_strlen(*str)) // s'il reste rien dans str
		ft_strclr(*str);
	else
		*str += (i + 1); // sinon incrémenter str
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*str[10000] = {NULL};
	int				ret1;
	char			*buf;
	int				ret2;

	//printf("\n---\nfd = %i\n---\n", fd);
	//printf("\n---\nstr[fd] = %s\n---\n", str[fd]);
	if (!line || fd < 0 || !(buf = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	if ((ret1 = reach_nl_or_EOF(fd, &str[fd], &buf)) == -1)
		return (-1);
	ret2 = cp_str_in_line(line, &str[fd], &ret1);
	return (ret2);
}
