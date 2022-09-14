/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:52:54 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 22:30:39 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal_set(t_fractol *f)
{
	if (f->values.define_set == 1)
		f->values.range = mandelbrot_does_it_converge(f, f->values.mx, \
		f->values.my);
	else if (f->values.define_set == 2)
		f->values.range = julia_does_it_converge(f, f->values.mx, \
		f->values.my);
}

void	draw_the_set(t_fractol *f, int color)
{
	int				x;
	int				y;
	unsigned int	k;

	mandelbrot_values(f);
	x = 0;
	while (x <= f->values.cx)
	{
		f->values.mx = f->values.min_re + x * f->values.factor_x;
		y = 0;
		while (y <= f->values.cy)
		{
			f->values.my = f->values.max_im - y * f->values.factor_y;
			check_fractal_set(f);
			if (f->values.range == f->values.max_iterations)
				improved_mlx_pixel_put(&(f->img), x, y, color);
			else
			{	
				set_colors(f);
				improved_mlx_pixel_put(&(f->img), x, y, f->values.rgb);
			}
			y++;
		}
		x++;
	}
}

void	re_render(t_fractol *f)
{
	mlx_clear_window(f->mlx, f->win);
	draw_the_set(f, BLACK);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	menu(f);
}
