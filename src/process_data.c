/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:57:10 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/19 16:58:24 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_minmax_values(t_dat *dat)
{
	int	dat_sz;

	dat_sz = (dat->map_c.clen) * (dat->map_c.llen) - 1;
	dat->map_c.x_min = dat->map_p[dat_sz].x;
	dat->map_c.y_min = dat->map_p[dat_sz].y;
	dat->map_c.x_max = dat->map_p[dat_sz].x;
	dat->map_c.y_max = dat->map_p[dat_sz].y;
	while (dat_sz--)
	{
		if (dat->map_p[dat_sz].x < dat->map_c.x_min)
			dat->map_c.x_min = dat->map_p[dat_sz].x;
		if (dat->map_p[dat_sz].y < dat->map_c.y_min)
			dat->map_c.y_min = dat->map_p[dat_sz].y;
		if (dat->map_p[dat_sz].x > dat->map_c.x_max)
			dat->map_c.x_max = dat->map_p[dat_sz].x;
		if (dat->map_p[dat_sz].y > dat->map_c.y_max)
			dat->map_c.y_max = dat->map_p[dat_sz].y;
	}
}

void	adjust_coord(t_dat *dat)
{
	int	dat_sz;

	get_minmax_values(dat);
	dat_sz = (dat->map_c.clen) * (dat->map_c.llen);
	while (dat_sz--)
	{
		dat->map_p[dat_sz].x += dat->map_c.x_min * -1 + 10;
		dat->map_p[dat_sz].y += dat->map_c.y_min * -1 + 10;
	}
}

void	load_color(t_dat *dat, int i_dat, char *hexcolor)
{
	int	i_hex;
	int	i_rgb;
	int	c;

	dat->map_p[i_dat].rgb[0] = 0;
	dat->map_p[i_dat].rgb[1] = 0;
	dat->map_p[i_dat].rgb[2] = 0;
	i_hex = ft_strlen(hexcolor) - 1;
	i_rgb = 2;
	while (hexcolor[i_hex] != 'x')
	{
		c = 0;
		if (hexcolor[i_hex - 1] != 'x')
			c++;
		dat->map_p[i_dat].rgb[i_rgb] = ft_ahtoi(&(hexcolor[i_hex - c]));
		i_rgb--;
		hexcolor[i_hex - c] = 0;
		i_hex = i_hex - c - 1;
	}
}

void	load_points(t_dat *dat, char *line)
{
	static int	i;
	int			j;
	char		**points;
	char		**coord_color;

	j = 0;
	points = ft_split(line, ' ');
	while (points[j])
	{
		coord_color = ft_split(points[j], ',');
		dat->map_p[i * dat->map_c.llen + j].x = j * dat->map_c.case_sz
			* cos(0.5236) + i * dat->map_c.case_sz * cos(2.618)
			+ ft_atoi(coord_color[0]) * dat->map_c.z_scale * cos(-1.571);
		dat->map_p[i * dat->map_c.llen + j].y = j * dat->map_c.case_sz
			* sin(0.5236) + i * dat->map_c.case_sz * sin(2.618)
			+ ft_atoi(coord_color[0]) * dat->map_c.z_scale * sin(-1.571);
		if (coord_color[1])
		{
			load_color(dat, i * dat->map_c.llen + j, coord_color[1]);
		}
		ft_free_2d(&coord_color);
		j++;
	}
	ft_free_2d(&points);
	i++;
}

void	load_map(t_dat *dat, char **argv, int argc)
{
	char	*line;
	int		fd;

	init_dat(dat, argv, argc);
	fd = open(argv[1], 0);
	line = get_next_line(fd);
	while (line)
	{
		line = ft_strtrim_free(line, " \n", &line);
		load_points(dat, line);
		free(line);
		line = get_next_line(fd);
	}
	adjust_coord(dat);
	free(line);
	close(fd);
}
