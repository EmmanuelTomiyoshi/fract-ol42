/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:55:52 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 21:55:52 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy (char *dest, const char *src, size_t size)
{
 size_t i;

 if (size > 0)
 {
  i = 0;

  while (src[i] != '\0' && i < size -1)
  {
   dest[i] = src[i];
   i++;
  }
  dest[i] = '\0';
 }
 return (ft_strlen(src));
}
