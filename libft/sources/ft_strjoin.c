/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:53:46 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 12:40:51 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new_str;

	new_str = NULL;
	if (s1 && s2)
	{
		if (!(new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcpy(new_str, s1);
		ft_strcat(new_str, s2);
	}
	return (new_str);
}
