/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:45 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/14 12:31:41 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define WIN_W 800
# define WIN_H 800
# define ZOOM_FACTOR 0.066
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "ft_printf.h"
# include "defines.h"
# define STDIN 0
# define STDOUT 1
# define STDERR 2
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_values
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			cx;
	double			cy;
	double			mx;
	double			my;
	double			kx;
	double			ky;
	double			factor_x;
	double			factor_y;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double 			old_re;
	double 			old_im;
	int				r;
	int				g;
	int				b;
	int				rgb;
	unsigned int	range;
	unsigned int	max_iterations;
	unsigned int	define_set;
	unsigned int	n;
}					t_values;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_values	values;
}			t_fractol;

void	improved_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_rgb(int r, int g, int b);
int		close_window(t_fractol *f);
void	error_exit(int error_status);
void	set_dimensions(t_fractol *f, char **argc);
void	reset_dimensions(t_fractol *f);
void	re_render(t_fractol *fractol);
int		zoom(int button, int x, int y, t_fractol *fractol);
double	get_scaled_x(t_fractol *f, int x);
double	get_scaled_y(t_fractol *f, int y);
int		check_for_args(t_fractol *f, int argc, char **argv);
int		handle_key(int keycode, t_fractol *fractol);
int		handle_mouse(int button, int x, int y, t_fractol *fractol);
void	open_window(t_fractol *fractol);
void	render(t_fractol *fractol);
void	set_colors(t_fractol *f);
void	mandelbrot_values(t_fractol *fractol);
void	check_mlx(t_fractol *f);
int		julia_does_it_converge(t_fractol *f, double re, double im);
int		mandelbrot_does_it_converge(t_fractol *f, double re, double im);
void	menu(t_fractol *f);
int		does_it_converge(t_fractol *f, double re, double im);
int		julia_does_it_converge(t_fractol *f, double re, double im);
void	check_fractal_set(t_fractol *f);
void	draw_the_set(t_fractol *f, int color);
double	ft_atof(const char *str);
int		ft_is_num(char *nbr);


#endif