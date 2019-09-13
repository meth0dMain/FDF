/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:27:15 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 13:34:51 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len-- > 0)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
