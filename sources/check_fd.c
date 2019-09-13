/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:38:36 by ndremora          #+#    #+#             */
/*   Updated: 2019/03/21 10:57:26 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_is_hex(const char *str)
{
	int i;

	if ((str[0] != 0) && ((str[1] != 120) && (str[1] != 88)))
		return (0);
	i = 2;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && (str[i] < 65 || str[i] > 70) \
		&& (str[i] < 97 || str[i] > 102))
			return (0);
		i++;
	}
	return ((i > 8 || i < 3) ? -1 : (int)strtol(str, NULL, 0));
}

char	*readfile(char **argv)
{
	int		fd;
	char	*bigline;
	int		ret;
	char	buff[1000001];

	bigline = NULL;
	if ((ft_strstr(argv[1], ".fdf")) == 0)
		ft_error("Error: Not a valid file. Goodbye");
	if ((fd = open(argv[1], O_RDONLY)) < 0 || read(fd, NULL, 0) < 0)
		ft_error("Error: Can't open() file. Goodbye");
	while ((ret = read(fd, buff, 1000000)) > 0)
	{
		buff[ret] = '\0';
		if (!bigline)
			bigline = ft_strdup(buff);
		else
			bigline = ft_strjoin(bigline, buff);
	}
	close(fd);
	return (bigline);
}

void	check_fd(char **argv, t_fdf *fdf)
{
	char	*bigline;

	bigline = NULL;
	bigline = readfile(argv);
	if (bigline == NULL)
		ft_error("Empty file");
	count_x_and_y(bigline, '\n', ' ', fdf);
	do_split_n(bigline, fdf);
	ft_strdel(&bigline);
}
