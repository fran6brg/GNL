
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 06:03:39 by fberger           #+#    #+#             */
/*   Updated: 2019/01/20 21:23:49 by fberger          ###   ########.fr       */
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

	(void)argc;
	//count = 0;
	fd1 = open(argv[1], O_RDONLY);
	while (get_next_line(fd1, &line) == 1)
	{
			//count++;
			ft_putendl(line);
			free(line);
	}
	free(line);
	close(fd1);
	//printf("******************************** count = %i\n", count);
	return (0);
}
