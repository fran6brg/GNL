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

static int swap_to_split_nl(char **str, char **line, char *to_split)
{
	int len;
	char *tmp;

	len = ft_strchr(to_split, '\n') - to_split + 1;
	tmp = ft_strdup(to_split);
	free(to_split);
	*line = ft_strsub(tmp, 0, len - 1);
	*str = ft_strsub(tmp, len, ft_strlen(tmp) - len);
	free(tmp);
	return (1);
}

static int cp_str_in_line(char **str, char **line)
{
	char *tmp;
	//printf("call A\n");
	if (ft_strchr(*line, '\n') && swap_to_split_nl(str, line, *str))
	{
		//printf("from cp >>>> newline\n");
		return (1);
	}
	// pas de newline donc cp l'entierté de str dans line on va lire +
	//printf("from cp pas de newline\n");
	tmp = ft_strdup(*line);
	free(*line);
	*line = ft_strjoin(*str, tmp);
	free(tmp);
	return (0);
}

static int reach_NLorEOF(int fd, char *buf, char **line, char **str)
{
	int ret;
	char *tmp;
	char	prev;

	prev = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 1 || *str)
	{
		if (ret > 0) // ok
			prev = ret;
		if (ret == -1) // ok
				return (ret);

		//printf("\nread 10 more | ret = %i prev = %i | *line = -%s- BUF = -%s-\n", ret, prev, *line, buf);

		if (ret == 0) // si EOF, renvoyer 1 une dernière fois si str
		{
			if (*str != NULL)
			{
				//printf("check 1 buf = %s\n", buf);
				//printf("check 1 str = %s et line = %s\n", *str, *line);
				if (cp_str_in_line(str, line) == 0)
						*str = NULL;
				//printf("check 1 str = %s et line = %s\n", *str, *line);
				//printf("ret %i from b1 \n", ret);
				return (1);
			}
			//printf("return 0 ?\n");
			return (0);
		}
		// join buf à line : ok
		buf[ret] = '\0';
		tmp = ft_strdup(*line);
		(*line ? free(*line) : "");
		*line = ft_strjoin(tmp, buf);
		(tmp ? free(tmp) : "");
		//printf("check 2a str = -%s- et line = -%s-\n", *str, *line);
		if (ft_strchr(*line, '\n') && swap_to_split_nl(str, line, *line)) // splitter si line contient un /n
		{
				//printf("ahhh str = -%s- et line = -%s-\n", *str, *line);
				//printf("ret %i from b2 \n", ret);
				return (ret);
		}
		//printf("check 2b str = %s et line = %s\n", *str, *line);
		//printf("fin read\n");
	}
	if (ret < prev)
	{
		//printf("check 3 str = %s et line = %s\n", *str, *line);
		//printf("\nhere we are : ret = %i et prev = %i\n\n", ret, prev);
		return (1);
	}
	//printf("ret = %i | BUFFF = -%s-\n", ret, buf);
	//printf("end B : ret = %i\n", ret);
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[10000] = {NULL};
	char		*buf;
	int			ret;

	//printf("\n\n\n\nback\n");
	//printf("\n\n\nback in this shit : *str == NULL : %s \n", *str == NULL ? "true" : "false");
	//printf("\n\n\nback in this shit : *str = -%s- \n", *str);
	if (!line || fd < 0 || BUFF_SIZE < 1 || !(*line = ft_strnew(BUFF_SIZE)))
	{
			printf("wtf ret -1\n");
			return (-1);
	}
	if (*str && cp_str_in_line(str, line))
	{
			//printf("ret 1 from A \n");
			return (1);
	}
	if (!ft_strchr(*line, '\n'))
			*str = NULL;
	//printf("ok start reading\n");
	buf = ft_strnew(BUFF_SIZE);
	ret = reach_NLorEOF(fd, buf, line, str);
	if (ret == -1)
	{
			//printf("\nret -1\n");
			return (-1);
	}
	if (ret == 0 && !*str)
	{
			//printf("\nret 0\n");
			return (ret);
	}
	//printf("\nby default ret 1\n");
	//printf("this free is ok\n");
	(buf ? free(buf) : "");
	return (1);
}
