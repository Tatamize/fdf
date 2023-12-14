/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_coordinate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 09:10:37 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 07:29:31 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_positive(int item, double *list)
{
	double	min;
	int		i;

	i = 0;
	min = list[i];
	while (i < item)
	{
		if (min > list[i])
			min = list[i];
		i++;
	}	
	if (min > 0)
		return ;
	i = 0;
	while (i < item)
	{
		list[i] = list[i] - min;
		i++;
	}
}

int	ft_get_max(int item, double *list)
{
	double	max;
	int		i;

	i = 0;
	max = list[i];
	while (i < item)
	{
		if (max < list[i])
			max = list[i];
		i++;
	}
	return ((int)ceil(max));
}

void	ft_get_iso_y(t_maps *p_map)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	x = 0;
	y = 0;
	p_map->iso_y = malloc((sizeof p_map->iso_y) * (p_map->item + 1));
	if (p_map->iso_y == NULL)
		err_free_exit(NULL, p_map, "malloc for altdata failed\n");
	while (i < p_map->item)
	{
		while ((int)x < p_map->w)
		{
			p_map->iso_y[i] = (x / 2) + (y / 2) - (p_map->alt[i]);
			i++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_get_iso_x(t_maps *p_map)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	x = 0;
	y = 0;
	p_map->iso_x = malloc((sizeof p_map->iso_x) * (p_map->item + 1));
	if (p_map->iso_x == NULL)
		err_free_exit(NULL, p_map, "malloc for altdata failed\n");
	while (i < p_map->item)
	{
		while ((int)x < p_map->w)
		{
			p_map->iso_x[i] = (sqrt(3) * x / 2) - (sqrt(3) * y / 2);
			i++;
			x++;
		}
		x = 0;
		y++;
	}
	ft_move_positive(p_map->item, p_map->iso_x);
	ft_move_positive(p_map->item, p_map->iso_y);
	p_map->img_w = ft_get_max(p_map->item, p_map->iso_x) + 1;
	p_map->img_y = ft_get_max(p_map->item, p_map->iso_y) + 1;
}

void	ft_iso_withspace(t_maps *p)
{
	int	i;

	i = 0;
	while (i < p->item)
	{
		p->iso_y[i] = p->iso_y[i] * p->space;
		p->iso_x[i] = p->iso_x[i] * p->space;
		p->iso_y[i] = round(p->iso_y[i]);
		p->iso_x[i] = round(p->iso_x[i]);
		i++;
	}
}
