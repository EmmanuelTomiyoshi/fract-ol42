/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:25:32 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 21:25:32 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
	int	res = 0;
	int	sign = 1;
	int	i = 0;

	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;

	if (nptr[i] == '-' || nptr[i] == '+')
    {
		if (nptr[i] == '-')
        	sign = -1;
        i++;
    }

    while(nptr[i])
    {
        if(!ft_isdigit(nptr[i]))
          return (sign*res);
        res = res*10 + nptr[i] - '0';
        i++;
    }
    return (sign*res);
}
