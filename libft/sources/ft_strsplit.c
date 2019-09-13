/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:53:19 by ndremora          #+#    #+#             */
/*   Updated: 2019/03/19 13:20:34 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		counter(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	**make_array(const char *s, char c, int words_count)
{
	char	**array;
	char	*word;
	int		i;

	i = 0;
	if ((array = (char **)malloc(sizeof(char *) * (words_count + 1))))
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = ft_cut_word(s, c)))
				{
					ft_free_array(array, i);
					return (NULL);
				}
				array[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		array[i] = NULL;
	}
	return (array);
}

char	**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (make_array(s, c, counter(s, c)));
}
