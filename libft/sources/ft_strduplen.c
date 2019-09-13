/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduplen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:26:59 by ndremora          #+#    #+#             */
/*   Updated: 2019/03/19 12:27:42 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strduplen(const char *str, size_t len)
{
	char			*str2;

	if (!(str2 = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(str2, str, len));
}
