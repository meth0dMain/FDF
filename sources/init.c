/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:14:20 by ndremora          #+#    #+#             */
/*   Updated: 2019/05/14 09:52:20 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf		*fdf_create(void)
{
	t_fdf		*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->w_width = 1920;
	fdf->w_height = 1080;
	fdf->height = 0;
	fdf->width = 0;
	fdf->z_min = 0;
	fdf->z_max = 0;
	return (fdf);
}

void		*fdf_init(t_fdf *fdf)
{
	if (!(fdf->mlx = mlx_init()))
		ft_error("FdF initialization error");
	if (!(fdf->win = mlx_new_window(fdf->mlx, fdf->w_width, fdf->w_height, \
			"Fdf ndremora school21")))
		ft_error("FdF initialization error");
	fdf->camera = camera_init(fdf);
	fdf->isometric = 1;
	return (fdf);
}

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		ft_error("Camera initialization error");
	/*camera->zoom = ft_min(fdf->w_width / fdf->width /2, \
			fdf->w_height / fdf->height /2);*/
	camera->zoom = fdf->w_width / fdf->width /2;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_dept = 1;
	//camera->x_move = fdf->w_width / fdf->width / 2;
	//camera->y_move = fdf->w_height / fdf->height / 2;
	camera->x_move =  fdf->width;
	camera->y_move =  fdf->height / 4;
	return (camera);
}

void		mlx_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, deal_key, fdf);
	mlx_hook(fdf->win, 17, 0, close_x, fdf);
	mlx_loop(fdf->mlx);
}
