/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:08:10 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/27 11:08:23 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *pointer;

	if (del && alst)
	{
		while (*alst)
		{
			pointer = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = pointer;
		}
		ft_memdel((void**)alst);
	}
}
