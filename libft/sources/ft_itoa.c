/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:53:07 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 12:37:53 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n, int sign)
{
	int		count;

	count = 1;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	if (sign == 1)
		return (count + 1);
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0 ? 1 : 0);
	len = length(n, sign);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	n = (n < 0 ? -n : n);
	while (len >= sign)
	{
		str[len] = (char)((n % 10) + 48);
		n = n / 10;
		len--;
	}
	if (sign == 1)
		str[len] = '-';
	return (str);
}
