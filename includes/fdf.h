/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:32:34 by ndremora          #+#    #+#             */
/*   Updated: 2019/05/14 09:52:20 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "/usr/local/include/mlx.h"
# include "mlx_keys.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_utls
{
	int				count;
	int				i;
}					t_utls;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_dots
{
	int				x1;
	int				y1;
	int				z1;
	int				color1;
	int				x2;
	int				y2;
	int				z2;
	int				color2;
}					t_dots;

typedef struct		s_dot
{
	int				dx;
	int				dy;
	int				sign_x;
	int				sign_y;
}					t_dot;

typedef struct		s_camera
{
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_dept;
	int				x_move;
	int				y_move;
}					t_camera;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*image_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				w_width;
	int				w_height;
	int				*coords_arr;
	int				*colors_arr;
	int				z_min;
	int				z_max;
	int				z_range;
	int				isometric;
	t_camera		*camera;
	double 			z_zoom;

}					t_fdf;

void				put_single_pix(t_fdf *fdf);
char				*readfile(char **argv);
void				do_split_z(char *check_z, t_fdf *fdf);
t_utls				skipper(const char *s, char c, char sp, t_utls p);
void				draw_line(t_dots p, t_fdf *fdf);
t_color				get_color(t_dots current, t_dots p, t_dot u);
void				parallel(t_fdf *fdf, t_dots *p);
void				iso(t_fdf *fdf, t_dots *p);
void				rotate_z(t_dots *p, double gamma);
void				rotate_y(t_dots *p, double beta);
void				rotate_x(t_dots *p, double alpha);
t_dots				create_point2(int x, int y, t_fdf *fdf);
t_dots				create_point(int x, int y, t_fdf *fdf);
t_dots				new_point2(t_fdf *fdf, int x, int y);
t_dots				new_point(t_fdf *fdf, int x, int y);
t_fdf				*fdf_create(void);
void				ft_error_fd(char *str, int num);
int					get_light(int start, int end, float percentage);
float				percent(int start, int end, int current);
void				put_pixel(t_fdf *fdf, int x, int y, t_color color);
int					close_x(void *param);
int					get_default_color(int z, int z_min, int z_range);
void				count_x_and_y(char const *s, char c, char sp, t_fdf *fdf);
void				do_split_space(char *checkline, t_fdf *fdf);
void				do_split_n(char *bigline, t_fdf *fdf);
void				check_fd(char **argv, t_fdf *fdf);
void				change_projection(int key, t_fdf *fdf);
void				change_z(int key, t_fdf *fdf);
void				rotate(int key, t_fdf *fdf);
void				move(int key, t_fdf *fdf);
void				zoom(int key, t_fdf *fdf);
int					deal_key(int key, void *param);
void				mlx_hooks(t_fdf *fdf);
void				draw(t_fdf *fdf);
t_camera			*camera_init(t_fdf *fdf);
void				*fdf_init(t_fdf *fdf);
int					ft_is_hex(const char *str);
void				ft_check_z(char *s);
void				ft_error(char *str);

#endif
