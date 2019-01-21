/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 09:47:17 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/17 11:02:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(new_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = f(s[i]);
		i++;
	}
	return (new_str);
}
