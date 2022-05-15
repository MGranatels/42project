/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:56:00 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/15 17:22:29 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	hook(int keycode, t_stk *data)
{
	if (keycode == 53)
		if (data->win_ptr)
			free(data->win_ptr);
	return (0);
}

int	main(void)
{
	t_stk data;

	//int		width;
	//int		height;
	//fd = open("map.ber", O_RDONLY);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "mlx_42");
	//mlx_xpm_file_to_image(mlx_ptr, "img.xml", &width, &height);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
	mlx_key_hook(data.win_ptr, hook, &data);
	mlx_loop(data.mlx_ptr);
}
