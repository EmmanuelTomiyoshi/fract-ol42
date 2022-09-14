/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:55:35 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 21:55:35 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *str)
{
 char *newStr;
 char *res;
 size_t leng;

 leng = ft_strlen(str)+1;
 newStr = (char *) ft_calloc(leng, sizeof(char));
 
 if (newStr == NULL)
  return (NULL);
 res = ft_memmove(newStr, str, leng);
 return (res);
 
}
