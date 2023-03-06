/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:02:43 by fcaetano          #+#    #+#             */
/*   Updated: 2023/01/23 11:23:45 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render(t_dat *dat)
{
	if (!dat)
		return (1);
	if (dat->win)
	{
		mlx_put_image_to_window(dat->mlx, dat->win, dat->img.mlx, 0, 0);
	}
	return (0);
}

int	handle_esc(int pkey, t_dat *dat)
{
	if (pkey == 53)
	{
		mlx_destroy_window(dat->mlx, dat->win);
		dat->win = NULL;
		exit(0);
	}
	return (0);
}

int	handle_close(void)
{
	exit(0);
	return (0);
}

void	ft_hook(t_dat *dat)
{
	mlx_loop_hook(dat->mlx, &render, dat);
	mlx_key_hook(dat->win, &handle_esc, dat);
	mlx_hook(dat->win, 17, 0, &handle_close, dat);
}

int	display_map(t_dat *dat)
{
	int	img_w;
	int	img_h;

	win_size(&(dat->map_c));
	dat->win = mlx_new_window(dat->mlx, dat->map_c.win_w, dat->map_c.win_h,
			"FdF");
	if (!dat->win)
	{
		free(dat->win);
		return (1);
	}
	ft_hook(dat);
	img_w = 16300;
	img_h = 16300;
	if (dat->map_c.x_max - dat->map_c.x_min + 20 < img_w)
		img_w = dat->map_c.x_max - dat->map_c.x_min + 20;
	if (dat->map_c.y_max - dat->map_c.y_min + 20 < img_h)
		img_h = dat->map_c.y_max - dat->map_c.y_min + 20;
	dat->img.mlx = mlx_new_image(dat->mlx, img_w, img_h);
	dat->img.addr = mlx_get_data_addr(dat->img.mlx, &dat->img.bpp,
			&dat->img.llen, &dat->img.endian);
	draw_map(*dat);
	mlx_loop(dat->mlx);
	return (0);
}
