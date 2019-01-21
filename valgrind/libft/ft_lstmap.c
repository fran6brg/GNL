/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:18:56 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/22 16:09:56 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	**tmp;

	newlst = NULL;
	tmp = &newlst;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		*tmp = ft_lstnew(f(lst)->content, f(lst)->content_size);
		tmp = &(*tmp)->next;
		lst = lst->next;
	}
	return (newlst);
}
