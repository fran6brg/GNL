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

/*static void	count_occurences(char *buf)
{
	int n;
	int i;

	n = 0;
	i = -1;
	while (buf[++i])
		if (buf[i] == '\n');
			n++;
	return (n);
}*/

static int	allocate_news_content(char *buf, t_list *element, int last_is_complete, char **line)
{
	int		i;
	t_list		*new;
	char		**strs;
	int		last_before;

	strs = ft_strsplit(buf, '\n');
	i = -1;
	// ça
	last_before = last_is_complete;
	if (last_is_complete == 0)
		element->content = ft_strjoin(element->content, strs[++i]);
	last_is_complete = 1;
	while (strs[++i])
	{
		new = ft_lstnew(buf, BUF_SIZE);
	  	new->content = (char *)malloc(sizeof(char) * ft_strlen(strs[i]));
		new->content = ft_strdup(strs[i]);
		ft_lstadd(&element, new);
		if (strs[i + 1] != '\0')
			new->content = ft_strjoin(new->content, "lol\n");
		printf("\n1 : 1..*n \n");
		element = new;
		//printf("element maillon = %s\n", element->content);
       		*line = element->content;
	}
	// voir avec ça
       	if (((int)ft_strlen(buf) -1) == (int)(ft_strrchr(buf, '\n') - buf))
       		return (1);
       	else
       		return (0);
}

int	get_next_line(const int fd, char **line)
{
	static int	nb_call;
	char		buf[BUF_SIZE + 1];
	int		index;
	static t_list	*element;
	static int	last_is_complete;

	if (!line || fd < 0 || BUF_SIZE < 1)
		return (-1);
	nb_call = (!nb_call ? 0 : nb_call);
	//printf("nb_call = %i\n", nb_call);
	last_is_complete = (!last_is_complete ? 1 : last_is_complete);
	if (nb_call == 0 || last_is_complete == 1)
		element = ft_lstnew(buf, BUF_SIZE);
	// lecture file jusqu'à sa fin
	while ((index = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (ft_strchr(buf,'\n') != NULL)
		{
			last_is_complete = allocate_news_content(buf, element, last_is_complete, line);
			nb_call += 1;
			return (1);
		}
		else
		{
		  //printf("last = %i\n", last_is_complete);
			if (last_is_complete == 1)
			{
			  	printf("\n2 : 0 n\n");
			  	//printf("content = %s\n", element->content);
				element->content = ft_strdup(buf);
				//printf("dup buff = %s\n", element->content);
				nb_call += 1;
				*line = element->content;
				//printf("b line = -%s-\n\n\n", element->content);
				return (1);
			}
			else
			{
			  	printf("\n3 : 0 n + dernier incomplet\n");
				element->content = ft_strjoin(element->content, buf);
				//printf("join maillon + buf = %s\n", element->content);
				nb_call += 1;
				*line = element->content;
				//printf("c line = -%s-\n\n\n", element->content);
				return (1);
			}
		}
	}
	nb_call += 1;
	return (0);
}
