/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:53:32 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/09 12:53:32 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	begin;
	unsigned int	end;
	const char		*new_str;

	if (!s)
		return (NULL);
	new_str = s;
	if (*s == 0)
		return ((char *)new_str);
	begin = 0;
	end = (unsigned int)ft_strlen(s);
	while ((s[begin] >= 9 && s[begin] <= 13) || s[begin] == 32)
		begin++;
	if (begin == ft_strlen(s))
		return (ft_strnew(0));
	while (end != 0 && ((s[end - 1] >= 9 && s[end - 1] <= 13)
	|| s[end - 1] == 32))
		end--;
	return (ft_strsub(s, begin, (end - begin)));
}
