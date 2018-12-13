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

static int split_third_param(char **str, char **line, char *to_split)
{
	int len;
	char *tmp;

	len = ft_strchr(to_split, '\n') - to_split + 1;
	tmp = ft_strdup(to_split);
	(to_split ? free(to_split) : "");
	*line = ft_strsub(tmp, 0, len - 1);
	*str = ft_strsub(tmp, len, ft_strlen(tmp) - len);
	(tmp ? free(tmp) : "");
	return (1);
}

static int cp_str_in_line(char **str, char **line)
{
	char *tmp;

	if (ft_strchr(*str, '\n') && split_third_param(str, line, *str))
		return (1);
	tmp = ft_strdup(*line);
	(*line ? free(*line) : "");
	*line = ft_strjoin(*str, tmp);
	(tmp ? free(tmp) : "");
	*str = NULL;
	return (0);
}

static int reach_NLorEOF(int fd, char *buf, char **line, char **str)
{
	int ret;
	char *tmp;
	char	prev;

	//printf("reach_NLorEOF : str = -%s- | line = -%s- \n", str[fd], *line);
	prev = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 1 || *str)
	{
		if (ret > 0) // ok
			prev = ret;
		if (ret == 0) // si EOF, renvoyer 1 une dernière fois si str
		{
			if (*str != NULL)
			{
				//printf("reach_NLorEOF 1\n");
				cp_str_in_line(str, line);
				return (1); // si EOF mais il reste qqchose a retourner
			}
			//printf("reach_NLorEOF 2\n");
			return (0); // si EOF + il reste rien a retourner
		}
		// join buf à line : ok
		buf[ret] = '\0';
		tmp = ft_strdup(*line);
		(*line ? free(*line) : "");
		*line = ft_strjoin(tmp, buf);
		(tmp ? free(tmp) : "");
		if (ft_strchr(*line, '\n') && split_third_param(str, line, *line)) // splitter si line contient un /n
		{
				//printf("reach_NLorEOF 2\n");
				return (ret);
		}
	}
	if (ret == -1) // ok
				return (ret);
	if (ret < prev) // EOF pendant le while
	{
		//printf("reach_NLorEOF 3 : fd = %i | str = -%s- | line = -%s- \n", fd, str[fd], *line);
		return (1);
	}
	//printf("reach_NLorEOF 4 : str = -%s- | line = -%s- \n", str[fd], *line);
	return (0);
}





int	get_next_line(const int fd, char **line)
{
	static char	*str[10000] = {NULL};
	char		*buf;
	int			ret;
	int		split;

	// checkerror
	//printf("back in this shit : str = -%s- | line = -%s- \n", str[fd], *line);
	if (!line || fd < 0 || BUFF_SIZE < 1 || !(*line = ft_strnew(BUFF_SIZE)))
	{
			return (-1);
	}

	split = -1; // 0 = str vide | 1 = str pas vide
	if (str[fd] && (split = cp_str_in_line(&str[fd], line)))
	{
		//printf("get_next_line 1\n");
		return (1);
	}

	buf = ft_strnew(BUFF_SIZE);
	ret = reach_NLorEOF(fd, buf, line, &str[fd]);
	if (ret == -1)
	{
			return (-1);
	}
	if (ret == 0 && !str[fd] && split == -1)
	{
			//printf("get_next_line 2 : str = -%s- | line = -%s- \n", str[fd], *line);
			return (ret);
	}

	(buf ? free(buf) : "");
	return (1);
}
// comment ca fini :
// reach_NLorEOF return 0 quand lecture est finie + str vide
// comment ca devrait finir
// a chaque passage de str a line return 1 jusqu a ce que line soit vide

// static int protect_join(char *src, char *s1)
// {
// 	char *tmp;
//
// 	tmp = ft_strdup(src);
// 	(src ? free(src) : "");
// 	src = ft_strjoin(s1, tmp);
// 	(tmp ? free(tmp) : "");
// 	return (1);
// }
