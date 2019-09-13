/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:30 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 13:35:36 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	*str2;

	str2 = (char *)str;
	len = ft_strlen(str2);
	while (str2[len] != c && len > 0)
		len--;
	if (str2[len] == c)
		return (&str2[len]);
	return (NULL);
}
