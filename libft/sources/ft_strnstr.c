/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:27 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 13:15:29 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	const char	*tmp;
	const char	*res;
	size_t		i;

	if (*sub == '\0')
		return ((char *)str);
	tmp = sub;
	while (*str && len > 0)
	{
		res = str;
		i = len;
		while (*sub && *res && *res == *sub && i > 0)
		{
			i--;
			res++;
			sub++;
			if (*sub == '\0')
				return ((char *)str);
		}
		len--;
		sub = tmp;
		str++;
	}
	return (NULL);
}
