/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:40:14 by tpiras            #+#    #+#             */
/*   Updated: 2023/02/05 12:36:05 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_l;

	new_l = malloc(sizeof(t_list));
	if (!new_l)
		return (NULL);
	new_l -> content = content;
	new_l -> next = NULL;
	return (new_l);
}
