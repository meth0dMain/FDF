/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:35:09 by ndremora          #+#    #+#             */
/*   Updated: 2019/05/14 09:52:20 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_dots	new_point(t_fdf *fdf, int x, int y)
{
	t_dots p;

	p = create_point(x, y, fdf);
	p.x1 = p.x1 * fdf->camera->zoom - fdf->width * fdf->camera->zoom / 2;
	p.y1 = p.y1 * fdf->camera->zoom - fdf->height * fdf->camera->zoom / 2;
	p.x2 = p.x2 * fdf->camera->zoom - fdf->width * fdf->camera->zoom / 2;
	p.y2 = p.y1;
	(fdf->camera->alpha) ? rotate_x(&p, fdf->camera->alpha) : 0;
	(fdf->camera->beta) ? rotate_y(&p, fdf->camera->beta) : 0;
	(fdf->camera->gamma) ? rotate_z(&p, fdf->camera->gamma) : 0;
	fdf->isometric ? iso(fdf, &p) : parallel(fdf, &p);
	return (p);
}

t_dots	create_point(int x, int y, t_fdf *fdf)
{
	t_dots	point;
	int		index;
	int		index2;

	index = fdf->width * y + x;
	index2 = fdf->width * y + (x + 1);
	point.x1 = x;
	point.x2 = x + 1;
	point.y1 = y;
	point.y2 = y;
	point.z1 = fdf->coords_arr[index] * fdf->z_zoom;
	point.z2 = fdf->coords_arr[index2] * fdf->z_zoom;
	point.color1 = (fdf->colors_arr[index]) ? fdf->colors_arr[index] : \
			get_default_color(point.z1, fdf->z_min, fdf->z_range);
	point.color2 = (fdf->colors_arr[index2]) ? fdf->colors_arr[index2] : \
			get_default_color(point.z2, fdf->z_min, fdf->z_range);
	return (point);
}

t_dots	new_point2(t_fdf *fdf, int x, int y)
{
	t_dots p;

	p = create_point2(x, y, fdf);
	p.x1 = p.x1 * fdf->camera->zoom - fdf->width * fdf->camera->zoom / 2;
	p.y1 = p.y1 * fdf->camera->zoom - fdf->height * fdf->camera->zoom / 2;
	p.x2 = p.x1;
	p.y2 = p.y2 * fdf->camera->zoom - fdf->height * fdf->camera->zoom / 2;
	(fdf->camera->alpha) ? rotate_x(&p, fdf->camera->alpha) : 0;
	(fdf->camera->beta) ? rotate_y(&p, fdf->camera->beta) : 0;
	(fdf->camera->gamma) ? rotate_z(&p, fdf->camera->gamma) : 0;
	fdf->isometric ? iso(fdf, &p) : parallel(fdf, &p);
	return (p);
}

t_dots	create_point2(int x, int y, t_fdf *fdf)
{
	t_dots	point;
	int		index;
	int		index2;

	index = fdf->width * y + x;
	index2 = fdf->width * (y + 1) + x;
	point.x1 = x;
	point.x2 = x;
	point.y1 = y;
	point.y2 = y + 1;
	point.z1 = fdf->coords_arr[index] * fdf->z_zoom;
	point.z2 = fdf->coords_arr[index2] * fdf->z_zoom;
	point.color1 = (fdf->colors_arr[index]) ? fdf->colors_arr[index] : \
			get_default_color(point.z1, fdf->z_min, fdf->z_range);
	point.color2 = (fdf->colors_arr[index2]) ? fdf->colors_arr[index2] : \
			get_default_color(point.z2, fdf->z_min, fdf->z_range);
	return (point);
}
