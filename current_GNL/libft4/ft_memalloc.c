/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 08:01:48 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/21 11:40:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	if (!(zone = (void *)malloc(size)))
		return (NULL);
	ft_bzero(zone, size);
	return (zone);
}
