/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_util_err.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 12:44:15 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 07:21:20 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_message_exit(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

void	err_free_exit(char *str, t_maps *mapdata, char *s)
{
	int	i;

	i = 0;
	if (str != NULL)
		free(str);
	if (mapdata != NULL)
	{
		if (mapdata->data != NULL)
			free(mapdata->data);
		if (mapdata->alt != NULL)
			free(mapdata->alt);
		if (mapdata->color != NULL)
			free(mapdata->color);
		if (mapdata->iso_y != NULL)
			free(mapdata->iso_y);
		if (mapdata->iso_x != NULL)
			free(mapdata->iso_x);
	}
	write(2, s, ft_strlen(s));
	exit (1);
}
