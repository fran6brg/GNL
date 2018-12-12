/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:38:17 by fberger           #+#    #+#             */
/*   Updated: 2018/12/01 20:01:55 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
// 1..* README ok / 1..* test ?
# define BUFF_SIZE 10

int get_next_line(const int fd, char **line);

#endif
