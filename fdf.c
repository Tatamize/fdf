/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 08:49:32 by kito          #+#    #+#                 */
/*   Updated: 2021/12/02 08:49:46 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_maps	map;
	t_para	para;
	t_data	bk;
	t_data	newimg;
	char	*s;

	if (argc != 2)
		err_message_exit("one file name is needed\n");
	s = ft_get_mapdata(&map, argv[1], &para);
	bk.img = mlx_new_image(para.mlx, map.win_w, map.win_y);
	bk.addr = mlx_get_data_addr(bk.img,
			&bk.bits_per_p, &bk.line_leng, &bk.endian);
	newimg.img = mlx_new_image(para.mlx, map.img_w, map.img_y);
	newimg.addr = mlx_get_data_addr(newimg.img,
			&newimg.bits_per_p, &newimg.line_leng, &newimg.endian);
	mlx_put_image_to_window(para.mlx, para.win, bk.img, 0, 0);
	mlx_put_image_to_window(para.mlx,
		para.win, newimg.img, map.space - 1, map.space - 1);
	ft_make_wire_h(&map, newimg);
	ft_make_wire_v(&map, newimg);
	ft_make_griddot(&map, newimg);
	mlx_key_hook(para.win, my_key_hook, &para);
	mlx_loop(para.mlx);
	return (0);
}

// __attribute__((destructor))
// static void destructor()
// {
// 	system("leaks -q fdf");
// }
