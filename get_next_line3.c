/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:37:59 by fberger           #+#    #+#             */
/*   Updated: 2018/12/01 20:01:38 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		*buf;
	int			ret;
	char		*tmp;
	int			len;

	if (!line || fd < 0 || BUF_SIZE < 1)
		return (0);
	*line = ft_strnew(BUF_SIZE);
	// si str alors copier coller dans line 
	if (str)
	{
		//printf("inspect str\n");
		if (ft_strchr(*line, '\n'))
		{
            len = ft_strchr(str, '\n') - str + 1;
            tmp = ft_strdup(str);
            free(str);
            // raccourcir str au besoin
            *line = ft_strsub(tmp, 0, len);
            // mettre le solde dans str pour le prochain call
            str = ft_strsub(tmp, len + 1, ft_strlen(tmp) - len);
			free(tmp);
            return (1);
        }
	}
	buf = ft_strnew(BUF_SIZE);
	while ((ret = read(fd, buf, BUF_SIZE)) >= 1)
	{
		// join buf dans line jusqu a \n
		if (ret < 1)
			return (ret);
		// pour terminer la string buf, verifier si reelement besoin
		buf[ret] = '\0';
		tmp = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(tmp, buf);
		free(tmp);
		// si \n
		//printf("build str\n");
		if (ft_strchr(*line, '\n'))
		{
			len = ft_strchr(*line, '\n') - *line + 1;
			tmp = ft_strdup(*line);
			free(*line);
			// raccourcir line au besoin
			*line = ft_strsub(tmp, 0, len);
			//printf("line = %s\n", *line);
			// mettre le solde dans str pour le prochain call
			str = ft_strsub(tmp, len + 1, ft_strlen(tmp) - len);
			free(tmp);
			return (1);
		}
	}
	free(buf);
	//printf("\nfin\n");
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
