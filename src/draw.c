/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:01:19 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 22:10:10 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	improved_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr;
	dest += (y * data-> line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	menu(t_fractol *f)
{
	mlx_set_font(f->mlx, f->win, \
	"-Misc-Fixed-Medium-R-Normal--20-200-75-75-C-100-ISO10646-1");
	mlx_string_put(f->mlx, f->win, 16, 56 + 680, YELLOW, "zoom  = SCROLL");
	mlx_set_font(f->mlx, f->win, \
	"-Misc-Fixed-Medium-R-Normal--20-200-75-75-C-100-ISO10646-1");
	mlx_string_put(f->mlx, f->win, 16, 80 + 680, YELLOW, "reset = R");
	mlx_set_font(f->mlx, f->win, \
	"-Misc-Fixed-Medium-R-Normal--20-200-75-75-C-100-ISO10646-1");
	mlx_string_put(f->mlx, f->win, 16, 104 + 680, YELLOW, "exit  = ESC");
}
