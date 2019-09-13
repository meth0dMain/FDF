/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:35:29 by ndremora          #+#    #+#             */
/*   Updated: 2019/03/20 10:51:47 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso(t_fdf *fdf, t_dots *p)
{
	int sum;
	int sub;

	sum = p->x1 + p->y1;
	sub = p->x1 - p->y1;
	p->x1 = (int)(sub * cos(0.523599));
	p->y1 = (int)(-p->z1 + sum * sin(0.523599));
	p->x1 += fdf->w_width / 2 + fdf->camera->x_move - fdf->width;
	p->y1 += (fdf->w_height + fdf->height * fdf->camera->zoom) / 3 \
			+ fdf->camera->y_move;
	sum = p->x2 + p->y2;
	sub = p->x2 - p->y2;
	p->x2 = (int)(sub * cos(0.523599));
	p->y2 = (int)(-p->z2 + sum * sin(0.523599));
	p->x2 += fdf->w_width / 2 + fdf->camera->x_move - fdf->width;
	p->y2 += (fdf->w_height + fdf->height * fdf->camera->zoom) / 3 \
			+ fdf->camera->y_move;
}

void	parallel(t_fdf *fdf, t_dots *p)
{
	p->x1 += fdf->w_width / 2 + fdf->camera->x_move - fdf->width;
	p->y1 += (fdf->w_height + fdf->height * fdf->camera->zoom) / 3 \
			+ fdf->camera->y_move;
	p->x2 += fdf->w_width / 2 + fdf->camera->x_move - fdf->width;
	p->y2 += (fdf->w_height + fdf->height * fdf->camera->zoom) / 3 \
			+ fdf->camera->y_move;
}

void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == KEY_END)
		fdf->isometric = 1;
	else if (key == KEY_HOME)
		fdf->isometric = 0;
	draw(fdf);
}

void	change_z(int key, t_fdf *fdf)
{
	if (key == KEY_PAGE_UP)
		fdf->camera->z_dept -= 0.1;
	else if (key == KEY_PAGE_DOWN)
		fdf->camera->z_dept += 0.1;
	if (fdf->camera->z_dept < 0.1)
		fdf->camera->z_dept = 0.1;
	else if (fdf->camera->z_dept > 5)
		fdf->camera->z_dept = 5;
	draw(fdf);
}
