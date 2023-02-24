/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:22:11 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/05 13:31:00 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_cycle(t_list *lst, void *(*f)(void *),
		void (*del)(void *), t_list *new_l)
{
	t_list	*pointer;

	pointer = new_l;
	while (lst)
	{
		new_l = ft_lstnew(f(lst -> content));
		if (!new_l)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&pointer, del);
			return (NULL);
		}
		lst = lst -> next;
		ft_lstadd_back(&pointer, new_l);
	}
	return (pointer);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*pointer;

	if (!f || !lst)
		return (NULL);
	new_l = ft_lstnew(f(lst -> content));
	if (!new_l)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	if (lst -> next == NULL)
		return (new_l);
	lst = lst -> next;
	pointer = ft_cycle(lst, f, del, new_l);
	return (pointer);
}
