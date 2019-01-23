
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 06:03:39 by fberger           #+#    #+#             */
/*   Updated: 2019/01/23 21:38:43 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "libft/includes/libft.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char		*line;
	int			fd1;
	//int 		count;

	(void)argv[argc];
	//count = 0;
	//fd1 = open(argv[1], O_RDONLY);
	fd1 = 100000000;
	while (get_next_line(fd1, &line) > 0)
	{
			//count++;
			printf("%s\n", line);
			free(line);
	}
	free(line);
	close(fd1);
	//printf("******************************** count = %i\n", count);
	return (0);
}
