


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 06:03:39 by fberger           #+#    #+#             */
/*   Updated: 2018/12/01 19:59:58 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int	fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
	  	//printf("--------\nline = -%s-\n--------\n", line);
	  	//printf("main : -%s-\n\n", line);
	  	printf("%s", line);
	  	free(line);
	}
	return (0);
}
