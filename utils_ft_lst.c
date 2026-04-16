/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:37:19 by varandri          #+#    #+#             */
/*   Updated: 2026/04/16 12:34:52 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1 ;
	node->next = NULL ;
	return (node);
}

size_t	lst_size(t_list *list)
{
	t_list	*node;
	size_t	i;

	node = list;
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

t_list	*lst_last(t_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	lst_add_front(t_list **list, t_list *node)
{
	if (!list || !node)
		return ;
	node->next = *list;
	*list = node;
}

void	lst_add_back(t_list **list, t_list *node)
{
	t_list	*last;

	if (!node || !list)
		return ;
	if (!*list)
	{
		*list = node;
		return ;
	}
	last = lst_last(*list);
	last->next = node;
}
