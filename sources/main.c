/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:42:57 by ndremora          #+#    #+#             */
/*   Updated: 2019/04/03 09:06:17 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **argv)
{
	t_fdf		*fdf;

	if (ac != 2)
		ft_error("Error: Map Arg wrong");
	fdf = fdf_create();
	check_fd(argv, fdf);
	fdf_init(fdf);
	draw(fdf);
	mlx_hooks(fdf);
	return (0);
}
