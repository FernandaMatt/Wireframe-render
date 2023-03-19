/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:57:01 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/19 16:58:14 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_map(t_dat dat)
{
	long unsigned int	i;
	long unsigned int	j;

	j = 0;
	while (j < dat.map_c.clen)
	{
		i = 0;
		while (i < dat.map_c.llen)
		{
			if (i + 1 < dat.map_c.llen)
				draw_line(dat, i + j * dat.map_c.llen,
					i + j * dat.map_c.llen + 1);
			if (j + 1 < dat.map_c.clen)
				draw_line(dat, i + j * dat.map_c.llen,
					i + j * dat.map_c.llen + dat.map_c.llen);
			i++;
		}
		j++;
	}
}
