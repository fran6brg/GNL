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

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (0);
	*line = ft_strnew(BUFF_SIZE);
	//i si str alors copier coller dans line
	if (str)
	{
			//printf("2-a : str exist = -%s-\n", str);
			//printf("inspect str\n");
			if (ft_strchr(*line, '\n'))
			{
							//printf("2-b : newline has been detected\n");
							//i calculer la distance jusqu'au premier \n
	            len = ft_strchr(str, '\n') - str;
							//printf("len = %i\n", len);
	            tmp = ft_strdup(str);
	            free(str);
	            //i raccourcir str au besoin
	            *line = ft_strsub(tmp, 0, len);
	            //i mettre le solde dans str pour le prochain call
	            str = ft_strsub(tmp, len, ft_strlen(tmp) - len);
							free(tmp);
	            return (1);
	    }
			tmp = ft_strdup(*line);
			free(*line);
			*line = ft_strjoin(str, tmp);
			free(tmp);
	}
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 1 || str)
	{
		//printf("1[%i] : buf = -%s-\n || buf = -%i-\n", ret, buf, (int)buf[0]);
		if (ret == 0)
		{
				*line = ft_strdup(str);
				str = NULL;
				//printf("break\n");
				return (1);
		}
		if (ret < 0 && !str)
		{
				//printf("return %i\n", ret);
				return (ret);
		}
		buf[ret] = '\0';
		//i pointer sur line pour le join
		tmp = ft_strdup(*line);
		free(*line);
		//i join buf dans line jusqu a \n
		*line = ft_strjoin(tmp, buf);
		free(tmp);
		//i si \n
		if (ft_strchr(*line, '\n'))
		{
			//printf("3 : line contains 1..* newlines\n");
			len = ft_strchr(*line, '\n') - *line + 1;
			//printf("\nbuf = -%s- | len = %i\n", buf, len);
			tmp = ft_strdup(*line);
			free(*line);
			//i raccourcir line au besoin
			*line = ft_strsub(tmp, 0, len);
			//printf("line = -%s-\n", *line);
			//i mettre le solde dans str pour le prochain call
			str = ft_strsub(tmp, len, ft_strlen(tmp) - len);
			//printf("solde str = -%s-\n", str);
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
