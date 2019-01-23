/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 09:59:16 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/22 21:15:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p_b;

	p_b = (unsigned char *)b;
	while (len > 0)
	{
		*p_b++ = c;
		len--;
	}
	return (b);
}
