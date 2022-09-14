/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:28:16 by etomiyos          #+#    #+#             */
/*   Updated: 2022/09/13 21:28:16 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list    *tmp;

    if (!del || !lst || !*lst)
        return ;
    while (lst && *lst)
    {
        tmp = (*lst) -> next;
        ft_lstdelone(*lst, del);
        *lst = tmp;
    }
}
