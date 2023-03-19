/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:49:36 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/19 16:57:49 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_data_sz(t_dat *dat, char *file)
{
	int		fd;
	char	*line;
	char	**points;

	fd = open(file, 0);
	if (fd > 0)
	{
		dat->map_c.clen = 0;
		line = get_next_line(fd);
		line = ft_strtrim_free(line, " \n", &line);
		points = ft_split(line, ' ');
		dat->map_c.llen = ft_array_len(points);
		ft_free_2d(&points);
		while (line)
		{
			dat->map_c.clen++;
			free(line);
			line = get_next_line(fd);
		}
	}
	close(fd);
}

void	ft_free_2d(char ***pptr)
{
	int	sz;

	sz = ft_array_len(*pptr);
	while (sz > 0)
	{
		free(pptr[0][sz - 1]);
		sz--;
	}
	free(pptr[0]);
}

int	dist_pts(t_map_p pt_i, t_map_p pt_f)
{
	int	x;
	int	y;

	x = (pt_f.x - pt_i.x) * (pt_f.x - pt_i.x);
	y = (pt_f.y - pt_i.y) * (pt_f.y - pt_i.y);
	return (sqrt((x + y)));
}

int	color(t_map_p *pi, t_map_p *pf)
{
	int	d;

	d = dist_pts(*pi, *pf);
	if (d)
	{
		pi->rgb[0] += (pf->rgb[0] - pi->rgb[0]) / d;
		pi->rgb[1] += (pf->rgb[1] - pi->rgb[1]) / d;
		pi->rgb[2] += (pf->rgb[2] - pi->rgb[2]) / d;
	}
	return (rgb_encode((char)pi->rgb[0], (char)pi->rgb[1], (char)pi->rgb[2]));
}

void	win_size(t_map_c *cfg)
{
	int	dif_x;
	int	dif_y;

	dif_x = cfg->x_max - cfg->x_min;
	dif_y = cfg->y_max - cfg->y_min;
	if (dif_x + 2 * cfg->case_sz < cfg->win_w)
		cfg->win_w = dif_x + 20;
	if (dif_y + 2 * cfg->case_sz < cfg->win_h)
		cfg->win_h = dif_y + 20;
}
