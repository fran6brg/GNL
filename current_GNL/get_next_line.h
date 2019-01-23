/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:38:17 by fberger           #+#    #+#             */
/*   Updated: 2019/01/15 01:47:39 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# include "libft4/includes/libft.h"
// gcc -Wall -Wextra -Werror -g get_next_line.c get_next_line.h libft4/libft.a main.c
# include "libft/libft.h"
// gcc -Wall -Wextra -Werror -g get_next_line.c get_next_line.h libft/libft.a main.c
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define BUFF_SIZE 10

int get_next_line(const int fd, char **line);

#endif
