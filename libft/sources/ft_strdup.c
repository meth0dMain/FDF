/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:16 by ndremora          #+#    #+#             */
/*   Updated: 2019/03/19 12:22:43 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*str2;
	size_t			len;

	len = ft_strlen(str);
	if (!(str2 = ft_strnew(len)))
		return (NULL);
	ft_strcpy(str2, str);
	return (str2);
}
