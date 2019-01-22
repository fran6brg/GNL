/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:59:03 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/22 19:37:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	long int	nbr;
	size_t		len;
	char		*str;

	nbr = n;
	len = ft_nofdig(nbr);
	if (!(str = ft_strnew(nbr < 0 ? ++len : len)))
		return (NULL);
	if (nbr == 0)
		str[len - 1] = nbr + '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr != 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
