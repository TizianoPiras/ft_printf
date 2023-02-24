/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:14:27 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/05 13:03:01 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*step;

	if (new == NULL || lst == NULL)
		return ;
	step = *lst;
	if (step == NULL)
	{
		*lst = new;
		return ;
	}
	while (step -> next != NULL)
		step = step -> next;
	step -> next = new;
}
