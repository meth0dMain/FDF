/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:35:58 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 12:38:22 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	while (len-- > 0)
	{
		if (*(unsigned char *)src == (unsigned char)c)
			return ((unsigned char*)src);
		src++;
	}
	return (NULL);
}
