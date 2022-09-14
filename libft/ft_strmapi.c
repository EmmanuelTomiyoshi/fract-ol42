/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:56:04 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 21:56:04 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    size_t  i;

    if (!(str = ft_strdup(s)))
        return (NULL);
    i = 0;
    while (str[i])
    {
        str[i] = (*f)(i, str[i]);
        i++;
    }
    return (str);
}
