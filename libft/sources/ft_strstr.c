/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:33 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 13:15:59 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *sub_str)
{
	const char *a;
	const char *b;

	if (*sub_str == '\0')
		return ((char *)str);
	while (*str)
	{
		a = str;
		b = sub_str;
		while (*b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return ((char *)str);
		str++;
	}
	return (NULL);
}
