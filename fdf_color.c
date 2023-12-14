/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 14:25:24 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 07:12:24 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	ft_x_value(char *str)
{
	long	value;
	int		i;

	value = 0;
	i = 0;
	if (ft_strlen(str) > 8)
		return (0x00FFFFFF);
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			value = (16 * value) + (str[i] - 48);
		else if (str[i] >= 65 && str[i] <= 70)
			value = (16 * value) + (str[i] - 55);
		else if (str[i] >= 97 && str[i] <= 102)
			value = (16 * value) + (str[i] - 87);
		else
			return (0x00FFFFFF);
		i++;
	}
	return (value);
}

long	ft_get_colorvalue(char *str)
{
	int		i;
	long	value;
	int		minus;

	i = 0;
	value = 0;
	minus = 1;
	if (str[0] == '\0')
		return (0x00FFFFFF);
	if (ft_strncmp(str, "0x", 2) == 0)
	{	
		str = &str[2];
		value = ft_x_value(str);
		return (value);
	}
	else
		return ((long)ft_atoi(str));
}

long	ft_get_color(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ',')
			return (ft_get_colorvalue(&s[i + 1]));
		i++;
	}
	return (0X00FFFFFF);
}

void	ft_make_color(t_maps *p_map)
{
	int	i;

	i = 0;
	p_map->color = malloc((sizeof p_map->color) * (p_map->item + 1));
	if (p_map->color == NULL)
		err_free_exit(NULL, p_map, "malloc for altdata failed\n");
	while (i < p_map->item)
	{
		p_map->color[i] = ft_get_color(p_map->data[i]);
		i++;
	}
	p_map->color[i] = '\0';
}

int	ft_get_grad(int i, int s, int e, t_maps *p)
{
	int	r;
	int	g;
	int	b;
	int	m;
	int	ra;

	m = 0;
	ra = (p->iso_y[e] - p->iso_y[s]) / (p->iso_x[e] - p->iso_x[s]);
	if ((int)p->iso_x[s] == (int)p->iso_x[e])
		m = (int)p->iso_y[s] - (int)p->iso_y[e];
	else if ((int)p->iso_y[s] == (int)p->iso_y[e])
		m = (int)p->iso_x[e] - (int)p->iso_x[s];
	else if (ra > 1 || ra < -1)
		m = (int)p->iso_y[e] - (int)p->iso_y[s];
	else
		m = (int)p->iso_x[e] - (int)p->iso_x[s];
	if (m < 0)
		m = m * -1;
	r = p->color[s] >> 16;
	g = p->color[s] >> 8 & 0xff;
	b = p->color[s] & 0xff;
	r = r + (((p->color[e] >> 16 & 0xff) - (p->color[s] >> 16 & 0xff)) * i / m);
	g = g + (((p->color[e] >> 8 & 0xff) - (p->color[s] >> 8 & 0xff)) * i / m);
	b = b + (((p->color[e] & 0xff) - (p->color[s] & 0xff)) * i / m);
	return (r << 16 | g << 8 | b);
}
