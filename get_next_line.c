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
	new = malloc(sizeof(new));
	while (buf[++i])
		n += (buf[i] == '\n' ? 1 : 0);
	i = -1;
	printf("n = %i\n", n);
	while (++i < n)
	{
		ptr = ft_strchr(buf,'\n');
		new->content = (char *)malloc(sizeof(char) * (ptr - buf));
		new = ft_lstnew(ft_strsub(buf, 0, (size_t)(ptr - buf)), (size_t)(ptr - buf));
		//printf("7 new = %s\n", new->content);
		ft_lstadd(&element, new);
		printf("7 nouveau maillon = %s\n", new->content);
		element = new;
		buf += (&ptr - &buf);
		n--;
	}
}

int	get_next_line(const int fd, char **line)
{
	static int	nb_call;
	char		buf[BUF_SIZE + 1];
	int		index;
	t_list		*element;
	static	int	last_complete;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	nb_call = (!nb_call ? 0 : nb_call); 
	printf("nb_call = %i\n", nb_call);
	if (nb_call == 0)
		element = ft_lstnew(buf, BUF_SIZE);
	// lecture par tranche de BUF_SIZE du contenu du file jusqu'à sa fin
	last_complete = 0;
	while ((index = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (ft_strchr(buf,'\n') != NULL)
		{
			allocate_news_content(buf, element, last_complete);
			return (1);
		}
		else
		{
			if (last_complete == 0)
			{
				element->content = ft_strdup(buf);
				printf("1 dup nouveau maillon = %s\n", element->content);
				return (1);
			}
			else
			{
				element->content = ft_strjoin(element->content, buf);
				printf("2 join maillon = %s\n", element->content);
				return (1);
			}
		}
	}
	nb_call = 1;
	// EOF = return != 1 pour stoper l'appel de GNL dans le main
	return (0);
}
