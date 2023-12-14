/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_mapping.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 08:48:52 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 07:15:21 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_ini_mapdata(t_maps *maps)
{
	maps->y = 0;
	maps->w = 0;
	maps->item = 0;
	maps->space = 0;
	maps->win_y = 0;
	maps->win_w = 0;
	maps->img_y = 0;
	maps->img_w = 0;
	maps->data = NULL;
	maps->alt = NULL;
	maps->color = NULL;
	maps->iso_y = NULL;
	maps->iso_x = NULL;
}

void	ft_check_size(char *s, t_maps *maps)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split(s, ' ');
	if (str == NULL)
		err_free_exit(s, NULL, "split failed!\n");
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	if (maps->w != 0 && maps->w != i && i != 0)
		err_free_exit(s, NULL, "width is different by line!\n");
	if (i != 0)
	{	
		maps->w = i;
		maps->y = maps->y + 1;
	}
	maps->item = maps->item + i;
	free(s);
}

void	ft_check_mapdata(t_maps *p, char *s)
{
	int		i;
	char	*temp;
	char	*org;

	i = 0;
	org = s;
	temp = NULL;
	while (s)
	{
		if (s[i] != '\n')
			i++;
		if (s[i] == '\n' || s[i] == '\0')
		{
			temp = ft_newstr(org, s, i);
			ft_check_size(temp, p);
			if (s[i] == '\0')
				break ;
			s = &s[i + 1];
			i = 0;
			temp = NULL;
		}
	}
	if (p->y == 0 || p->w == 0)
		err_free_exit(org, NULL, "no data in the file\n");
}

int	ft_get_space(t_maps *p_map)
{
	int	i;
	int	j;

	i = WIN_SIZE_X / p_map->img_w;
	j = WIN_SIZE_Y / p_map->img_y;
	if (i < 1 || j < 1)
		return (1);
	if (i == 1 || j == 1)
		return (2);
	if (i > j)
		return (j);
	else
		return (i);
}

char	*ft_get_mapdata(t_maps *p, char *file, t_para *para)
{
	char	*s;
	void	*mlx;
	void	*mlx_win;

	s = ft_s_ini(NULL);
	s = ft_readdata(file, s);
	ft_ini_mapdata(p);
	ft_check_mapdata(p, s);
	p->data = ft_get_strlist(s, ' ', (p->y * p->w), p);
	ft_make_alt(p);
	ft_make_color(p);
	ft_get_iso_y(p);
	ft_get_iso_x(p);
	p->space = ft_get_space(p);
	p->win_y = (p->img_y * p->space) + p->space - 1;
	p->win_w = (p->img_w * p->space) + p->space - 1;
	p->img_y = (p->img_y * p->space);
	p->img_w = (p->img_w * p->space);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, p->win_w, p->win_y, "FDF");
	para->mlx = mlx;
	para->win = mlx_win;
	ft_iso_withspace(p);
	return (s);
}
