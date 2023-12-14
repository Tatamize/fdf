/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_draw_wire_util.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 07:24:29 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 07:34:44 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line_h(int s, int e, t_maps *p, t_data *img)
{
	int	min;
	int	i;

	min = 1;
	i = 0;
	if ((int)p->iso_y[s] > (int)p->iso_y[e])
		min = -1;
	while (i < ((int)p->iso_y[e] - (int)p->iso_y[s]) * min)
	{
		my_pixel_put(img, (int)p->iso_x[s],
			(int)p->iso_y[s] + (i * min), ft_get_grad(i, s, e, p));
		i++;
	}	
}

void	ft_line_v(int s, int e, t_maps *p, t_data *img)
{
	int	min;
	int	i;

	min = 1;
	i = 0;
	if ((int)p->iso_x[s] > (int)p->iso_x[e])
		min = -1;
	while (i < (((int)p->iso_x[e] - (int)p->iso_x[s]) * min))
	{
		my_pixel_put(img, (int)p->iso_x[s] + (i * min),
			(int)p->iso_y[s], ft_get_grad(i, s, e, p));
		i++;
	}
}

void	ft_line_high(int s, int e, t_maps *p, t_data *img)
{
	int	min;
	int	i;
	int	r;
	int	temp;

	min = 1;
	i = 0;
	r = 0;
	temp = 0;
	if ((int)p->iso_y[s] > (int)p->iso_y[e])
		min = -1;
	while (i < ((int)p->iso_y[e] - (int)p->iso_y[s]) * min)
	{
		i++;
		r = (p->iso_x[e] - p->iso_x[s]) / (p->iso_y[e] - p->iso_y[s]) * i;
		temp = round(r);
		my_pixel_put(img, p->iso_x[s] + (temp * min),
			p->iso_y[s] + ((i - 1) * min), ft_get_grad(i, s, e, p));
	}
}

void	ft_line_low(int s, int e, t_maps *p, t_data *img)
{
	int	min;
	int	i;
	int	r;
	int	temp;

	min = 1;
	i = 0;
	r = 0;
	temp = 0;
	if ((int)p->iso_x[s] > (int)p->iso_x[e])
		min = -1;
	while (i < (((int)p->iso_x[e] - (int)p->iso_x[s]) * min))
	{
		i++;
		r = (p->iso_y[e] - p->iso_y[s]) / (p->iso_x[e] - p->iso_x[s]) * i;
		temp = round(r);
		my_pixel_put(img, p->iso_x[s] + ((i - 1) * min),
			p->iso_y[s] + (temp * min), ft_get_grad(i, s, e, p));
	}
}
