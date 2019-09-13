/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:22 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 12:41:08 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	char	*d;

	d = dst;
	while (*dst)
		dst++;
	while (*src && len-- > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (d);
}
