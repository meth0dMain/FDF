/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:14:44 by ndremora          #+#    #+#             */
/*   Updated: 2019/03/15 09:18:29 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	ft_error_fd(char *str, int num)
{
	ft_putstr(str);
	ft_putnbr(num);
	ft_putchar('\n');
	exit(0);
}
