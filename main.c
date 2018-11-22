/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 06:03:39 by fberger           #+#    #+#             */
/*   Updated: 2018/11/22 06:26:07 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char *argv[])
{
	int		fd;
	char	**line;

	(void)argc;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);
	return (1);
}
