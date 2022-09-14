/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:26:07 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/14 18:37:15 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_dimensions(t_fractol *f)
{
	f->values.min_re = -2.0;
	f->values.min_im = -2.0;
	f->values.max_re = 2.0;
	f->values.max_im = f->values.min_im + (f->values.max_re - f->values.min_re);
	f->values.max_im *= WIN_H / WIN_W;
}

void	set_dimensions(t_fractol *f, char **argc)
{
	f->values.max_iterations = 100;
	f->values.min_re = -2.0;
	f->values.min_im = -2.0;
	f->values.max_re = 2.0;
	f->values.max_im = f->values.min_im + (f->values.max_re - f->values.min_re);
	f->values.max_im *= WIN_H / WIN_W;
	if (f->values.define_set == 2)
	{
		f->values.kx = ft_atof(argc[2]);
		f->values.ky = ft_atof(argc[3]);
	}
}

void	set_colors(t_fractol *f)
{
	f->values.r = f->values.range + 30;
	f->values.g = f->values.range * 2 + 40;
	f->values.b = fmin(50 + f->values.range * 4, 255);
	f->values.rgb = create_rgb(f->values.r, f->values.g, \
	f->values.b);
}

void	mandelbrot_values(t_fractol *f)
{
	f->values.dx = f->values.max_re - f->values.min_re;
	f->values.dy = f->values.max_im - f->values.min_im;
	f->values.factor_x = f->values.dx / WIN_W;
	f->values.factor_y = f->values.dy / WIN_H;
	f->values.cx = WIN_W;
	f->values.cy = WIN_H;
}
