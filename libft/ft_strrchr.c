/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:56:16 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 21:56:16 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int	c)
{
	int i;

	i = ft_strlen(s);

	while (i >= 0)
	{
		if(s[i] == (char) c)
			return ((char*) s + i);
		i--;
	}
	return (NULL);
}
