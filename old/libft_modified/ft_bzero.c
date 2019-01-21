/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:43:14 by fberger           #+#    #+#             */
/*   Updated: 2018/11/13 22:53:06 by fberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n-- > 0)
		ptr[n] = 0;
}*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p_s;

	if (n != 0)
	{
		p_s = (unsigned char*)s;
		ft_memset(p_s, 0, n);
	}
}
