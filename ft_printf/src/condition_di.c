/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:40:44 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/22 20:41:12 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condition_di(va_list ptr)
{
	char	*x;
	int		y;

	y = 0;
	x = ft_itoa(va_arg(ptr, int));
	while (x[y])
	{
		write(1, &x[y], 1);
		y++;
	}
	free(x);
	return (y);
}
