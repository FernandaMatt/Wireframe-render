/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:29:26 by fcaetano          #+#    #+#             */
/*   Updated: 2023/01/18 13:51:57 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate_entry(int argc, char **argv, t_dat *dat)
{
	int		fd;
	int		ret;
	char	*temp;

	fd = open(argv[1], 0);
	if (fd < 0)
		return (1);
	else
		ret = validate_file(fd, dat);
	if (ret == 3 || ret == 4)
	{
		temp = get_next_line(fd);
		while (temp)
		{
			free(temp);
			temp = get_next_line(fd);
		}
	}
	if (argc == 4)
		ret = validate_params(argv);
	close(fd);
	return (ret);
}

int	validate_file(int fd, t_dat *dat)
{
	char	**points;
	char	*line;
	int		ret;

	line = get_next_line(fd);
	while (line)
	{
		line = ft_strtrim_free(line, " \n", &line);
		points = ft_split(line, ' ');
		ret = validate_points(points, *dat);
		if (ret)
		{
			free(line);
			ft_free_2d(&points);
			return (ret);
		}
		free(line);
		ft_free_2d(&points);
		line = get_next_line(fd);
	}
	return (0);
}

int	validate_points(char **points, t_dat dat)
{
	int		i;
	char	**p;

	i = 0;
	while (points[i])
	{
		if (dat.map_c.llen != ft_array_len(points))
			return (2);
		p = ft_split(points[i], ',');
		if (!check_int(p[0]) || check_max(p[0], "2147483647", "2147483648"))
		{
			ft_free_2d(&p);
			return (3);
		}
		if (p[1] != 0 && (!check_hex(p[1])))
		{
			ft_free_2d(&p);
			return (4);
		}
		ft_free_2d(&p);
		i++;
	}
	return (0);
}

int	validate_params(char **argv)
{
	if (!check_int(argv[2]) || !check_int(argv[3]))
		return (5);
	return (0);
}
