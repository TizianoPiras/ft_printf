/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:50:02 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/05 13:53:45 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst && lst)
	{
		list = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = list;
	}
	*lst = NULL;
}
