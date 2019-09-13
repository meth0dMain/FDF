/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:51:14 by ndremora          #+#    #+#             */
/*   Updated: 2019/03/29 18:40:24 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		deal_key(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	if (key == KEY_PAD_ADD || key == KEY_PAD_SUB)
		zoom(key, fdf);
	else if (key >= KEY_LEFT && key <= KEY_UP)
		move(key, fdf);
	else if ((key >= KEY_PAD_1 && key <= KEY_PAD_4) || \
			(key >= KEY_PAD_6 && key <= KEY_PAD_9))
		rotate(key, fdf);
	else if (key == KEY_PAGE_UP || key == KEY_PAGE_DOWN)
		change_z(key, fdf);
	else if (key == KEY_HOME || key == KEY_END)
		change_projection(key, fdf);
	return (0);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_PAD_2)
		fdf->camera->alpha += 0.05;
	else if (key == KEY_PAD_8)
		fdf->camera->alpha -= 0.05;
	else if (key == KEY_PAD_4)
		fdf->camera->beta -= 0.05;
	else if (key == KEY_PAD_6)
		fdf->camera->beta += 0.05;
	else if (key == KEY_PAD_7 || key == KEY_PAD_1)
		fdf->camera->gamma += 0.05;
	else if (key == KEY_PAD_3 || key == KEY_PAD_9)
		fdf->camera->gamma -= 0.05;
	draw(fdf);
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == KEY_PAD_ADD)
		fdf->camera->zoom += 2;
	else if (key == KEY_PAD_SUB)
		fdf->camera->zoom -= 2;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == KEY_LEFT)
		fdf->camera->x_move -= 10;
	else if (key == KEY_RIGHT)
		fdf->camera->x_move += 10;
	else if (key == KEY_UP)
		fdf->camera->y_move -= 10;
	else
		fdf->camera->y_move += 10;
	draw(fdf);
}

int		close_x(void *param)
{
	(void)param;
	exit(0);
}
