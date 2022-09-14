/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:25:47 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 21:25:47 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  *ft_calloc(size_t nelem, size_t elsize)
{
  void *ptr;

  ptr = malloc(nelem * elsize);
  if (ptr == NULL)
   return (NULL);
  
  ft_bzero(ptr, (nelem * elsize));
  return (ptr);
}