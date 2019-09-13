/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:13:15 by ndremora          #+#    #+#             */
/*   Updated: 2019/03/18 16:51:49 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_dots *p, double alpha)
{
	int old_y;

	old_y = p->y1;
	p->y1 = (int)(old_y * cos(alpha) + p->z1 * sin(alpha));
	p->z1 = (int)(-old_y * sin(alpha) + p->z1 * cos(alpha));
	old_y = p->y2;
	p->y2 = (int)(old_y * cos(alpha) + p->z2 * sin(alpha));
	p->z2 = (int)(-old_y * sin(alpha) + p->z2 * cos(alpha));
}

void	rotate_y(t_dots *p, double beta)
{
	int old_x;

	old_x = p->x1;
	p->x1 = (int)(old_x * cos(beta) + p->z1 * sin(beta));
	p->z1 = (int)(-old_x * sin(beta) + p->z1 * cos(beta));
	old_x = p->x2;
	p->x2 = (int)(old_x * cos(beta) + p->z2 * sin(beta));
	p->z2 = (int)(-old_x * sin(beta) + p->z2 * cos(beta));
}

void	rotate_z(t_dots *p, double gamma)
{
	int old_x;
	int old_y;

	old_x = p->x1;
	old_y = p->y1;
	p->x1 = (int)(old_x * cos(gamma) - old_y * sin(gamma));
	p->y1 = (int)(old_x * sin(gamma) + old_y * cos(gamma));
	old_x = p->x2;
	old_y = p->y2;
	p->x2 = (int)(old_x * cos(gamma) - old_y * sin(gamma));
	p->y2 = (int)(old_x * sin(gamma) + old_y * cos(gamma));
}
