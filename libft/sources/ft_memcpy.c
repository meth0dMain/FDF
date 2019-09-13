/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:06 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/17 14:31:19 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*d;

	d = (unsigned char *)dst;
	while (len-- > 0)
		*d++ = *(unsigned char *)src++;
	return ((unsigned char *)dst);
}
