/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:00:10 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/22 21:15:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			neg = -1;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			res = res * 10 + (str[i++] - 48);
			if (res < 0)
				return (neg == 1 ? -1 : 0);
		}
		else
			return (res * neg);
	}
	return (res * neg);
}
