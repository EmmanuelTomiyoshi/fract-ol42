/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:40:45 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/14 12:31:26 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keycode, t_fractol *f)
{
	if (keycode == 65307)
		close_window(f);
	else if (keycode == R)
	{
		reset_dimensions(f);
		re_render(f);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	if (button == SCROLL_UP)
	{
		f->values.dx = (f->values.max_re - f->values.min_re) * ZOOM_FACTOR;
		f->values.dy = (f->values.max_im - f->values.min_im) * ZOOM_FACTOR;
		f->values.min_re = get_scaled_x(f, x) - (f->values.dx / 4.0);
		f->values.max_re = get_scaled_x(f, x) + (f->values.dx / 4.0);
		f->values.min_im = get_scaled_y(f, y) - (f->values.dy / 4.0);
		f->values.max_im = get_scaled_y(f, y) + (f->values.dy / 4.0);
		f->values.max_iterations += 32;
		re_render(f);
	}
	else if (button == SCROLL_DOWN)
	{
		f->values.dx = (f->values.max_re - f->values.min_re) \
						* (1 / ZOOM_FACTOR);
		f->values.dy = (f->values.max_im - f->values.min_im) \
						* (1 / ZOOM_FACTOR);
		f->values.min_re = get_scaled_x(f, x) - f->values.dx / 1.25;
		f->values.max_re = get_scaled_x(f, x) + f->values.dx / 1.25;
		f->values.min_im = get_scaled_y(f, y) - f->values.dy / 1.25;
		f->values.max_im = get_scaled_y(f, y) + f->values.dy / 1.25;
		re_render(f);
	}
	return (0);
}
