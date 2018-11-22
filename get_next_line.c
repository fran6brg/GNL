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

static void	allocate_news_content(char *buf, t_list *element)
{
	int			n;
	int			i;
	t_list		*new;
	char		*ptr;

	n = 0;
	i = -1;
	while (buf[++i])
		n += (buf[i] == '\n' ? 1 : 0);
	i = -1;
	while (++i < n)
	{
		ptr = ft_strchr(buf,'\n');
		new = ft_lstnew(ft_strsub(buf, 0, (size_t)(&ptr - &buf)), BUF_SIZE);
		ft_lstadd(&element, new);
		printf("nouveau maillon = %s\n", new->content);
		element = new;	
		buf += (&ptr - &buf);
		n--;
	}
}

int	get_next_line(const int fd, char **line)
{
	static int	nb_call;
	char		buf[BUF_SIZE + 1];
	int			index;
	t_list		*element;

	(void)line;
	printf("1\n");
	nb_call = 0;
	element = ft_lstnew(buf, BUF_SIZE);
	while ((index = read(fd, buf, BUF_SIZE)) > 0)
	{
		//buf[index] = '\0';
		printf("2\n");
		if (ft_strchr(buf,'\n') != NULL)
		{
			printf("3\n");
			allocate_news_content(buf, element);
		}
		else
		{
			printf("4\n");
			if (nb_call == 0)
			{
				element->content = ft_strdup(buf);
				return (1);
				printf("nouveau maillon = %s\n", new->content);
			}
			else
			{
				element->content = ft_strjoin(element->content, buf);
				printf("nouveau maillon = %s\n", new->content);
			}
		}
	}
	nb_call = 1;
	return (0);
}
