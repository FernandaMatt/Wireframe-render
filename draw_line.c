/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:01:55 by fcaetano          #+#    #+#             */
/*   Updated: 2022/12/21 17:01:59 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_ppix(t_img img, int x, int y, int true_color)
{
	char	*pxl;

	if (x < 16300 && y < 16300)
	{
		pxl = img.addr + (y * img.llen) + (x * (img.bpp / 8));
		*(unsigned int *)pxl = true_color;
	}
}

int	rgb_encode(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

void	draw_line(t_dat dat, int i, int f)
{
	int	dist_x;
	int	dist_y;

	dist_x = ft_abs(dat.map_p[f].x - dat.map_p[i].x);
	dist_y = ft_abs(dat.map_p[f].y - dat.map_p[i].y);
	if (dist_x >= dist_y)
	{
		if (dat.map_p[i].x < dat.map_p[f].x)
			bresenham_x(dat.map_p[i], dat.map_p[f], dat.img);
		else
			bresenham_x(dat.map_p[f], dat.map_p[i], dat.img);
	}
	else
	{
		if (dat.map_p[i].y < dat.map_p[f].y)
			bresenham_y(dat.map_p[i], dat.map_p[f], dat.img);
		else
			bresenham_y(dat.map_p[f], dat.map_p[i], dat.img);
	}
}

void	bresenham_x(t_map_p pt_i, t_map_p pt_f, t_img img)
{
	int	a;
	int	b;
	int	p;

	a = 2 * (ft_abs(pt_f.y - pt_i.y));
	b = a - 2 * (ft_abs(pt_f.x - pt_i.x));
	p = a - (pt_f.x - pt_i.x);
	img_ppix(img, pt_i.x, pt_i.y, color(&pt_i, &pt_f));
	while (pt_i.x != pt_f.x || pt_i.y != pt_f.y)
	{
		if (p < 0)
			p += a;
		else
		{
			if (pt_i.y > pt_f.y)
				pt_i.y--;
			else
				pt_i.y++;
			p += b;
		}
		pt_i.x++;
		img_ppix(img, pt_i.x, pt_i.y, color(&pt_i, &pt_f));
	}
}

void	bresenham_y(t_map_p pt_i, t_map_p pt_f, t_img img)
{
	int	a;
	int	b;
	int	p;

	a = 2 * (ft_abs(pt_f.x - pt_i.x));
	b = a - 2 * (ft_abs(pt_f.y - pt_i.y));
	p = a - (pt_f.y - pt_i.y);
	img_ppix(img, pt_i.x, pt_i.y, color(&pt_i, &pt_f));
	while (pt_i.x != pt_f.x || pt_i.y != pt_f.y)
	{
		if (p < 0)
			p += a;
		else
		{
			if (pt_i.x > pt_f.x)
				pt_i.x--;
			else
				pt_i.x++;
			p += b;
		}
		pt_i.y++;
		img_ppix(img, pt_i.x, pt_i.y, color(&pt_i, &pt_f));
	}
}
