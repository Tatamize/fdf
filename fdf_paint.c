/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_paint.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 15:14:21 by kito          #+#    #+#                 */
/*   Updated: 2021/12/01 12:45:56 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_leng + x * (data->bits_per_p / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

void	my_paint_bk(int x, int y, t_data *data, int color)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (h < y)
	{
		while (w < x)
		{
			my_pixel_put(data, w, h, color);
			w++;
		}
		w = 0;
		h++;
	}
}

int	my_key_hook(int keycode, t_para *para)
{
	if (keycode == 53)
	{
		mlx_destroy_window(para->mlx, para->win);
		exit(0);
	}
	return (0);
}
