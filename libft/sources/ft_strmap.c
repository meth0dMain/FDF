/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:54:21 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 13:34:13 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new_str;

	if (!s)
		return (NULL);
	if (!(new_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = (f)(s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
