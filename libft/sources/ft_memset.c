/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:30:54 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 13:24:47 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	if (len == 0)
		return (str);
	while (len > 0)
	{
		((unsigned char *)str)[len - 1] = (unsigned char)c;
		len--;
	}
	return (str);
}
