/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:53:56 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/09 12:53:56 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_substr;

	new_substr = NULL;
	if (!s || !(new_substr = ft_strnew(len)))
		return (NULL);
	ft_strncpy(new_substr, &s[start], len);
	return (new_substr);
}
