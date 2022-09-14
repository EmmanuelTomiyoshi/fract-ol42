/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:14:47 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 22:26:06 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_scaled_x(t_fractol *f, int x)
{
	double	factor;

	f->values.dx = f->values.max_re - f->values.min_re;
	factor = f->values.dx / (double) WIN_W;
	return (f->values.min_re + x * factor);
}

double	get_scaled_y(t_fractol *f, int y)
{
	double	factor;

	f->values.dy = f->values.max_im - f->values.min_im;
	factor = f->values.dy / (double) WIN_H;
	return (f->values.max_im - y * factor);
}

int	julia_does_it_converge(t_fractol *f, double re, double im)
{
	f->values.n = 0;
	f->values.x = re;
	f->values.y = im;
	while (1)
	{
		f->values.old_re = re;
		f->values.old_im = im;
		re = pow(f->values.old_re, 2) - pow(f->values.old_im, 2);
		im = 2 * f->values.old_re * f->values.old_im;
		re += f->values.kx;
		im += f->values.ky;
		if ((fabs(re) > 2) || (fabs(im) > 2))
			return (f->values.n);
		if (f->values.n > f->values.max_iterations)
			return (f->values.max_iterations);
		f->values.n++;
	}
	return (0);
}

int	mandelbrot_does_it_converge(t_fractol *f, double re, double im)
{
	f->values.n = 0;
	f->values.x = re;
	f->values.y = im;
	while (1)
	{
		f->values.old_re = re;
		f->values.old_im = im;
		re = pow(f->values.old_re, 2) - pow(f->values.old_im, 2);
		im = 2 * f->values.old_re * f->values.old_im;
		re += f->values.x;
		im += f->values.y;
		if ((fabs(re) > 2) || (fabs(im) > 2))
			return (f->values.n);
		if (f->values.n > f->values.max_iterations)
			return (f->values.max_iterations);
		f->values.n++;
	}
	return (0);
}
