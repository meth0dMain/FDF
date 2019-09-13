/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:02 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 12:38:30 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t len)
{
	while (len-- > 0)
	{
		if (*(unsigned char *)str1 != *(unsigned char *)str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
	}
	return (0);
}
