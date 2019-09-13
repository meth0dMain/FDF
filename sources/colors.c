/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:40:35 by ndremora          #+#    #+#             */
/*   Updated: 2019/05/14 09:52:20 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			get_default_color(int z, int z_min, int z_range)
{
	float	percentage;

	percentage = (((float)z - z_min) / z_range);
	if (percentage < 0.1)
		return (0xFD00FF);
	else if (percentage < 0.2)
		return (0xFD00E7);
	else if (percentage < 0.3)
		return (0xFD00CB);
	else if (percentage < 0.4)
		return (0xFD00AF);
	else if (percentage < 0.5)
		return (0xFD0093);
	else if (percentage < 0.6)
		return (0xFD0077);
	else if (percentage < 0.7)
		return (0xFD005B);
	else if (percentage < 0.8)
		return (0xFD003F);
	else if (percentage < 0.9)
		return (0xFD0023);
	else
		return (0xFD0003);
}

t_color		get_color(t_dots current, t_dots p, t_dot u)
{
	float	percentage;
	t_color color;

	if (u.dx > u.dy)
		percentage = percent(p.x1, p.x2, current.x1);
	else
		percentage = percent(p.y1, p.y2, current.y1);
	color.red = get_light((p.color1 >> 16) & 0xFF, \
			(p.color2 >> 16) & 0xFF, percentage);
	color.green = get_light((p.color1 >> 8) & 0xFF, \
			(p.color2 >> 8) & 0xFF, percentage);
	color.blue = get_light(p.color1 & 0xFF, p.color2 & 0xFF, percentage);
	return (color);
}

int			get_light(int start, int end, float percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

float		percent(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0f : (placement / distance));
}
