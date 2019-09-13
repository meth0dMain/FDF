/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:51:06 by ndremora          #+#    #+#             */
/*   Updated: 2019/03/19 12:52:19 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_cut_word(const char *str, char c)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)str;
	i = 0;
	while (*tmp && *tmp != c)
	{
		tmp++;
		i++;
	}
	return (ft_strduplen(str, i));
}
