/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 10:54:57 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 08:35:11 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6000
# endif

# ifndef WIN_SIZE_X
#  define WIN_SIZE_X 1200
# endif

# ifndef WIN_SIZE_Y
#  define WIN_SIZE_Y 900
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_p;
	int		line_leng;
	int		endian;
}			t_data;

typedef struct s_maps{
	int		y;
	int		w;
	int		item;
	int		space;
	int		win_y;
	int		win_w;
	int		img_y;
	int		img_w;
	char	**data;
	int		*alt;
	long	*color;
	double	*iso_y;
	double	*iso_x;
}			t_maps;

typedef struct s_para{
	void	*mlx;
	void	*win;
}			t_para;

// fdf_util_err.c
void	err_message_exit(char *s);
void	err_free_exit(char *str, t_maps *mapdata, char *s);

// fdf_util.c
char	*ft_addc_free_s(char *s, char c);
char	*ft_addtext_free_s(char *s, char *text);
char	*ft_s_ini(char *ss);
char	*ft_newstr(char *org, char *str, int size);
char	*ft_readdata(char *file, char *s);

// fdf_mapping.c
void	ft_ini_mapdata(t_maps *maps);
void	ft_check_size(char *s, t_maps *maps);
void	ft_check_mapdata(t_maps *p, char *s);
int		ft_get_space(t_maps *p_map);
char	*ft_get_mapdata(t_maps *mapdata, char *file, t_para *para);

// fdf_strlist.c
char	**ft_data_strlist(char **src, char c, char *s);
char	**ft_get_strlist(char *s, char c, int size, t_maps *p);
int		ft_get_alt(char *s);
void	ft_make_alt( t_maps *p_map);

//fdf_coordinate.c
void	ft_move_positive(int item, double *list);
int		ft_get_max(int item, double *list);
void	ft_get_iso_y(t_maps *maps);
void	ft_get_iso_x(t_maps *maps);
void	ft_iso_withspace(t_maps *p);

// fdf_color.c
long	ft_x_value(char *str);
long	ft_get_colorvalue(char *str);
long	ft_get_color(char *s);
void	ft_make_color(t_maps *p_map);
int		ft_get_grad(int i, int s, int e, t_maps *p);

// fdf_paint.c
void	my_pixel_put(t_data *data, int x, int y, int color);
void	my_paint_bk(int x, int y, t_data *data, int color);
int		my_key_hook(int keycode, t_para *para);

//fdf_draw_wire.c
void	ft_make_griddot(t_maps *p, t_data img);
void	ft_make_line(int s, int e, t_maps *p, t_data *img);
void	ft_make_wire_h(t_maps *p, t_data img);
void	ft_make_wire_v(t_maps *p, t_data img);

//fdf_draw_wire_util.c
void	ft_line_h(int s, int e, t_maps *p, t_data *img);
void	ft_line_v(int s, int e, t_maps *p, t_data *img);
void	ft_line_high(int s, int e, t_maps *p, t_data *img);
void	ft_line_low(int s, int e, t_maps *p, t_data *img);

//fdf.c
int		main(int argc, char *argv[]);

#endif