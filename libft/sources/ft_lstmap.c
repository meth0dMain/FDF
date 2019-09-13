/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:07:58 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/27 11:08:18 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *start_list;

	if (lst && f)
	{
		if (!(newlist = (*f)(lst)))
			return (NULL);
		start_list = newlist;
		while (lst->next)
		{
			lst = lst->next;
			newlist->next = f(lst);
			newlist = newlist->next;
		}
		return (start_list);
	}
	return (NULL);
}
