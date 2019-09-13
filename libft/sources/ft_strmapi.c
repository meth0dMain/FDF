/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:54:18 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 13:35:59 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	i = 0;
	if (!s)
		return (NULL);
	if (!(new_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		new_str[i] = (f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
