
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 06:03:39 by fberger           #+#    #+#             */
/*   Updated: 2019/01/15 02:05:54 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int	fd;
	int i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	printf("bufsize = %i\n", BUFF_SIZE);
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
			i++;
	  	printf("\n************************\nmain : -%s-\n************************\n", line);
	  	//printf("%s", line);
	  	free(line);
	}
	free(line);
	printf("\n\ni = %i", i);
	return (0);
}

// int		fd;
// char	*str;
// int i;

// fd = open("test", O_RDONLY);
// i = close(fd);
// printf("i = : %d\n", i);
// i = read(fd, str, 125);
// i = get_next_line(fd, &str);
// printf("read = %d", i);
