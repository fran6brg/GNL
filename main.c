


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

#include "rendered/get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int	fd;
	int i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	printf("bufsize = %i\n", BUFF_SIZE);
	i = 0;
	while (get_next_line(-1, &line) == 1)
	{
			i++;
	  	//printf("--------\nline = -%s-\n--------\n", line);
	  	printf("\n************************\nmain : -%s-\n************************\n", line);
	  	//printf("%s", line);
	  	free(line);
	}
	printf("\n\ni = %i", i);
	return (0);
}
