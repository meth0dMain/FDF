/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_split_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 09:55:54 by ndremora          #+#    #+#             */
/*   Updated: 2019/05/14 09:52:20 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	do_split_n(char *bigline, t_fdf *fdf)
{
	int			i;
	char		**check_line_n;
	size_t		arr_size;

	i = -1;
	arr_size = fdf->width * fdf->height * sizeof(int);
	if (!(fdf->coords_arr = (int *)ft_memalloc(arr_size)))
		ft_error("Error: Memory error");
	if (!(fdf->colors_arr = (int *)ft_memalloc(arr_size)))
		ft_error("Error: Memory error");
	check_line_n = ft_strsplit(bigline, '\n');
	while (check_line_n[++i] != NULL)
	{
		do_split_space(check_line_n[i], fdf);
		ft_strdel(&check_line_n[i]);
	}
	free(check_line_n);
	fdf->z_range = fdf->z_max - fdf->z_min;
}

void	do_split_z(char *check_z, t_fdf *fdf)
{
	char		**str;
	static int	count;
	int			col;
	if (!count)
		count = 0;
	(!(str = ft_strsplit(check_z, ',')) ? \
		ft_error("Error: Empty split") : ft_check_z(str[0]));
	fdf->coords_arr[count] = ft_atoi(str[0]);
	if (fdf->coords_arr[count] > fdf->z_max)
		fdf->z_max = fdf->coords_arr[count];
	if (fdf->coords_arr[count] < fdf->z_min)
		fdf->z_min = fdf->coords_arr[count];
	if (str[1])
	{
		col = ft_is_hex(str[1]);
		col != -1 ? fdf->colors_arr[count] = col : ft_error("Error: !color");
	}
	ft_free_array(str, 2);
	count++;
}

void	do_split_space(char *check_line_n, t_fdf *fdf)
{
	char	**check_line;
	int		i;

	i = -1;
	check_line = ft_strsplit(check_line_n, ' ');
	while (check_line[++i] != NULL)
	{
		do_split_z(check_line[i], fdf);
		ft_strdel(&check_line[i]);
	}
	free(check_line);
}

void	ft_check_z(char *s)
{
	int		i;

	i = 0;
	if (!*s)
		ft_error("Error: Line read");
	while (s[i] != '\0')
	{
		if ((s[i] >= 33 && s[i] <= 42) || (s[i] >= 58 && s[i] <= 127))
			ft_error("Error: Found Forbidden Characters");
		if ((s[i] == '-' && !(ft_isdigit(s[i + 1]))) || s[i] == '\t')
			ft_error("Error: Found Forbidden Characters");
		i++;
	}
}
