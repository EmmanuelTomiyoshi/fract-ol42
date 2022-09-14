/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:57:51 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/14 12:25:12 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	open_window(t_fractol *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		exit(0);
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "fractol - by etomiyos");
	if (f->win == NULL)
		check_mlx(f->win);
	f->img.img = mlx_new_image(f->mlx, WIN_W, WIN_H);
	if (f->img.img == NULL)
		check_mlx(f->img.img);
	f->img.addr = mlx_get_data_addr(f->img.img,
			&(f->img.bits_per_pixel), &(f->img.line_length),
			&(f->img.endian));
}

void	render(t_fractol *f)
{
	draw_the_set(f, BLACK);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	menu(f);
}
