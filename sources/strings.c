/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:37:28 by ndremora          #+#    #+#             */
/*   Updated: 2019/05/14 09:52:20 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_utls	skipper(const char *s, char c, char sp, t_utls p)
{
	p.i = 0;
	p.count = 0;
	while (*s != '\0' && *s != c)
	{
		s++;
		p.i++;
		if (*s == sp)
		{
			while (*s == sp)
			{
				s++;
				p.i++;
			}
			if (*s != '\0' && *s != '\n')
				p.count++;
		}
	}
	p.count++;
	return (p);
}

void	count_x_and_y(char const *s, char c, char sp, t_fdf *fdf)
{
	t_utls p;

	p.count = 0;
	while (*s != '\0')
	{
		if (*s == c && *(s + 1) == c)
			ft_error_fd("Error: Empty line on line# ", fdf->height + 1);
		else if (*s == c)
			s++;
		if (*s != '\0')
		{
			fdf->height++;
			p = skipper(s, c, sp, p);
		}
		else
			p.i = 0;
		if (!fdf->width)
			fdf->width = p.count;
		else if (fdf->width != p.count)
			ft_error_fd("Error: Different width on line# ", fdf->height);
		s += p.i;
	}
	if (fdf->width != p.count)
		ft_error("Error: Different width");
}
