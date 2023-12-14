/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_draw_wire.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 12:45:22 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 07:26:51 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_make_griddot(t_maps *p, t_data img)
{
	int	i;

	i = 0;
	while (i < p->item)
	{
		my_pixel_put(&img, (int)p->iso_x[i], (int)p->iso_y[i], p->color[i]);
		i++;
	}	
}

void	ft_make_line(int s, int e, t_maps *p, t_data *img)
{
	int		temp;
	double	r;
	int		i;
	int		min;

	temp = 0;
	i = 0;
	r = 0;
	min = 1;
	if ((int)p->iso_x[s] == (int)p->iso_x[e])
	{
		ft_line_h(s, e, p, img);
		return ;
	}
	if ((int)p->iso_y[s] == (int)p->iso_y[e])
	{
		ft_line_v(s, e, p, img);
		return ;
	}
	r = (p->iso_y[e] - p->iso_y[s]) / (p->iso_x[e] - p->iso_x[s]);
	if (r > 1 || r < -1)
		ft_line_high(s, e, p, img);
	else
		ft_line_low(s, e, p, img);
	return ;
}

void	ft_make_wire_h(t_maps *p, t_data img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < p->y)
	{
		while (x < p->w - 1)
		{
			ft_make_line((y * p->w) + x, (y * p->w) + x + 1, p, &img);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_make_wire_v(t_maps *p, t_data img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < p->w)
	{
		while (y < p->y - 1)
		{
			ft_make_line((y * p->w) + x, (y * p->w) + x + p->w, p, &img);
			y++;
		}
		y = 0;
		x++;
	}
}
