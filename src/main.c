/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:01:51 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/19 16:58:00 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_dat(t_dat *dat, char **argv, int argc)
{
	int	n_points;

	n_points = (dat->map_c.clen) * (dat->map_c.llen);
	dat->map_p = malloc(sizeof(t_map_p) * (n_points));
	dat->map_c.z_scale = 1;
	dat->map_c.case_sz = 30;
	if (argc == 4)
	{
		dat->map_c.case_sz = ft_atoi(argv[2]);
		dat->map_c.z_scale = ft_atoi(argv[3]);
	}
	dat->map_c.win_h = 1100;
	dat->map_c.win_w = 2000;
	while (n_points--)
	{
		dat->map_p[n_points].rgb[0] = 255;
		dat->map_p[n_points].rgb[1] = 255;
		dat->map_p[n_points].rgb[2] = 0;
	}
}

int	check_error(t_dat *dat, int argc, char **argv)
{
	int	n;

	get_data_sz(dat, argv[1]);
	n = validate_entry(argc, argv, dat);
	if (!n)
		return (0);
	if (n == 1)
		ft_printf("Invalid fdf file name. Check file %s and permissions.",
			argv[1]);
	else if (n == 2)
		ft_printf("Wrong line length. All the lines must have the same \
number of points.");
	else if (n == 3)
		ft_printf("Wrong value in %s file. Check if all the points	\
are integer values.", argv[1]);
	else if (n == 4)
		ft_printf("Wrong color code in %s file. Check if all the colors are \
properly formatted as hexcolors [0xhexcode].", argv[1]);
	else if (n == 5)
		ft_printf("Wrong paramaters. case_size and z_scale must be integers.");
	return (1);
}

int	main(int argc, char **argv)
{
	t_dat	dat;

	if (argc == 2 || argc == 4)
	{
		if (check_error(&dat, argc, argv))
			return (1);
		load_map(&dat, argv, argc);
		dat.mlx = mlx_init();
		if (!dat.mlx)
			return (1);
		if (display_map(&dat))
			return (1);
		free(dat.map_p);
		free(dat.mlx);
	}
	else
		ft_printf("Wrong number of parameters. Usage:\
\n./fdf map_file.fdf <case_sz z_scale>");
	return (0);
}
