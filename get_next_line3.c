/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:37:59 by fberger           #+#    #+#             */
/*   Updated: 2018/11/22 06:40:28 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int		ret;
	char		*buf;
	int		i;

	//printf("1\n");
	/*if (!str)
	{
		if (!(str = (char *)ft_memalloc(2)))
			return (0);
		str[0] = 0;
		str[1] = '\0';
		}*/
	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (0);
	if (!(buf = (char *)ft_memalloc(BUF_SIZE + 1)))
	  	return (0);
	while ((i = read(fd, buf, BUF_SIZE)) > 0)
	{
		//printf("2\nbuf=%s\n", buf);
		if (ft_strchr(buf, '\n'))
		{
		  	if (str)
			{
				printf("<join : -%s- et -%s->\n\n", str, buf);
			  	str = ft_strjoin(str, buf);
			}
			else
			{
				printf("<dup : -%s->\n\n",  buf);
				str = ft_strdup(buf);
			}			
			*line = str;
			return (1);
		}
		if (*str)
			str = ft_strjoin(str, buf);
      		else
      			str = ft_strdup(buf);
	}
	//printf("3\n");
	return (0);
}
/*
  return :
  1 = keep going;
  other = stop;
  0) line = strnew(BUFF_SIZE)
  1) si str != null => tant qu'il n'y a pas de \n, strjoin les buf dans ta fonction sinon renvoie 1 et return 1
  2) sinon si str = NULL on strnew => on va lire + pr chaque buf on join et au premier \n return line
  3) laisse le ret finir l'appel à la fonction
  read > stock all dans str > strsub jusqu'à i pos du 1er \n
*/
