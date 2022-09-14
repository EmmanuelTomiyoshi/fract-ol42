/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:08:29 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/14 12:31:53 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_for_args(t_fractol *f, int argc, char **argv)
{
	if (argc < 2 || argc > 4 || argc == 3)
		return(ft_printf("%s%s%s", MSG0, MSG1, MSG2), 1);
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		f->values.define_set = 1;
	else if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10))
		return(ft_printf("%s%s%s", MSG0, MSG1, MSG2), 1);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5) \
		&& ft_is_num(argv[2]) && ft_is_num(argv[3]))
		f->values.define_set = 2;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5) \
		&& ft_is_num(argv[2]) && ft_is_num(argv[3]))
		return(ft_printf("%s%s", MSG3, MSG2), 1);
	else
		return(ft_printf("%s%s%s", MSG0, MSG1, MSG2), 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (!check_for_args(&fractol, argc, argv))
	{
		set_dimensions(&fractol, argv);
		open_window(&fractol);
		render(&fractol);
		mlx_hook(fractol.win, 17, 0, &close_window, &fractol);
		mlx_key_hook(fractol.win, &handle_key, &fractol);
		mlx_mouse_hook(fractol.win, &handle_mouse, &fractol);
		mlx_loop(fractol.mlx);	
	}
	return (0);
}

//4 parameters
//name julia
//float