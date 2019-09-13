/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:53:19 by ndremora          #+#    #+#             */
/*   Updated: 2019/05/14 09:52:20 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw(t_fdf *fdf)
{
	int		x;
	int		y;

	if (!(fdf->img = mlx_new_image(fdf->mlx, fdf->w_width, fdf->w_height)))
		ft_error("FdF image creation error");
	fdf->image_data = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel), \
			&(fdf->size_line), &(fdf->endian));
	y = -1;
	fdf->z_zoom = fdf->camera->zoom / fdf->camera->z_dept / 5;
	if (fdf->width == 1 && fdf->height == 1)
		put_single_pix(fdf);
	while (++y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x != fdf->width - 1)
				draw_line(new_point(fdf, x, y), fdf);
			if (y != fdf->height - 1)
				draw_line(new_point2(fdf, x, y), fdf);
			x++;
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->img);
}

void	draw_line(t_dots p, t_fdf *fdf)
{
	t_dot		u;
	t_dots		cur;
	int			error[2];

	cur = p;
	u.dx = ft_abs(p.x2 - p.x1);
	u.dy = ft_abs(p.y2 - p.y1);
	u.sign_x = p.x1 < p.x2 ? 1 : -1;
	u.sign_y = p.y1 < p.y2 ? 1 : -1;
	error[0] = u.dx - u.dy;
	while (cur.x1 != p.x2 || cur.y1 != p.y2)
	{
		put_pixel(fdf, cur.x1, cur.y1, get_color(cur, p, u));
		error[1] = error[0] * 2;
		if (error[1] > -u.dy)
		{
			error[0] -= u.dy;
			cur.x1 += u.sign_x;
		}
		if (error[1] < u.dx)
		{
			error[0] += u.dx;
			cur.y1 += u.sign_y;
		}
	}
}

void	put_pixel(t_fdf *fdf, int x, int y, t_color color)
{
	int		i;

	if (x > 0 && x < fdf->w_width && y > 0 && y < fdf->w_height)
	{
		i = x * 4 + fdf->size_line * y;
		fdf->image_data[i] = color.blue;
		fdf->image_data[i + 1] = color.green;
		fdf->image_data[i + 2] = color.red;
	}
}

void	put_single_pix(t_fdf *fdf)
{
	int		i;

	i = fdf->w_width / 2 * 1081 * 4 + fdf->size_line;
	fdf->image_data[i] = (char)253;
	fdf->image_data[i + 1] = (char)253;
	fdf->image_data[i + 2] = (char)253;
}
