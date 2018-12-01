/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:38:17 by fberger           #+#    #+#             */
/*   Updated: 2018/11/22 06:37:49 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "Libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

# define BUF_SIZE 5

int get_next_line(const int fd, char **line);

#endif
