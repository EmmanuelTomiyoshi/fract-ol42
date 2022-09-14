/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:55:42 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 21:55:42 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t leng;
    char *newStr;

    leng = ft_strlen(s1) + ft_strlen(s2) + 1;
    newStr = (char *) ft_calloc(leng, sizeof(char));

    ft_strlcat(newStr, s1, leng);
    ft_strlcat(newStr, s2, leng);

    return(newStr);
}
