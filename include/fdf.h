/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:56:05 by fcaetano          #+#    #+#             */
/*   Updated: 2023/03/19 17:01:04 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"

typedef struct s_img
{
	void				*mlx;
	char				*addr;
	int					bpp;
	int					llen;
	int					endian;
}						t_img;

typedef struct s_map_p
{
	int					x;
	int					y;
	int					rgb[3];
}						t_map_p;

typedef struct s_map_c
{
	long unsigned int	llen;
	long unsigned int	clen;
	int					z_scale;
	int					case_sz;
	int					win_w;
	int					win_h;
	int					x_min;
	int					y_min;
	int					x_max;
	int					y_max;
}						t_map_c;

typedef struct s_dat
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_map_p				*map_p;
	t_map_c				map_c;
}						t_dat;

void					win_size(t_map_c *cfg);
int						render(t_dat *dat);
void					ft_hook(t_dat *dat);
int						display_map(t_dat *dat);
void					draw_map(t_dat dat);
void					draw_line(t_dat dat, int i, int f);
void					bresenham_x(t_map_p pt_i, t_map_p pt_f, t_img img);
void					bresenham_y(t_map_p pt_i, t_map_p pt_f, t_img img);
int						rgb_encode(unsigned char red, unsigned char green,
							unsigned char blue);
void					img_ppix(t_img img, int x, int y, int true_color);
int						dist_pts(t_map_p pt_i, t_map_p pt_f);
int						color(t_map_p *pi, t_map_p *pf);
void					get_data_sz(t_dat *dat, char *file);
int						validate_entry(int argc, char **argv, t_dat *dat);
int						validate_file(int fd, t_dat *dat);
int						validate_points(char **points, t_dat dat);
int						validate_params(char **argv);
int						check_max(char *str, char *max, char *min);
int						check_int(char *number);
int						check_hex(char *hex);
void					ft_free_2d(char ***pptr);
void					load_map(t_dat *dat, char **argv, int argc);
void					init_dat(t_dat *dat, char **argv, int argc);
void					load_points(t_dat *dat, char *line);

#endif
