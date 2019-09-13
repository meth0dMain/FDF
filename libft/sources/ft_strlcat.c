/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:19 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 13:29:33 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	const char	*s;
	size_t		n;
	size_t		i;

	n = len;
	s = src;
	i = 0;
	while (n-- > 0 && *dst != '\0')
	{
		dst++;
		i++;
	}
	n = len - i;
	if (n == 0)
		return (i + ft_strlen(s));
	while (*s != '\0' && n > 1)
	{
		if (--n)
			*dst++ = *s;
		s++;
	}
	*dst = '\0';
	return (i + ft_strlen(src));
}
