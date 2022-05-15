/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:56:00 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/04 15:33:23 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <sys/fcntl.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	void	*img;
	//int		width;
	//int		height;

	//fd = open("map.ber", O_RDONLY);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx_42");
	//mlx_xpm_file_to_image(mlx_ptr, "img.xml", &width, &height);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
	mlx_loop(mlx_ptr);
}
