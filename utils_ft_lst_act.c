/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_act_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:15:30 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 06:05:17 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ac_list	*lst_ac_new(char *name)
{
	t_ac_list	*node;

	node = (t_ac_list *)malloc(sizeof(t_ac_list));
	if (!node)
		return (NULL);
	node->name = name;
	node->next = NULL ;
	return (node);
}

size_t	lst_ac_size(t_ac_list *list)
{
	t_ac_list	*node;
	size_t		i;

	node = list;
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

t_ac_list	*lst_ac_last(t_ac_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	lst_ac_add_back(t_ac_list **list, t_ac_list *node)
{
	t_ac_list	*last;

	if (!node || !list)
		return ;
	if (!*list)
	{
		*list = node;
		return ;
	}
	last = lst_ac_last(*list);
	last->next = node;
}

void	lst_ac_clear(t_ac_list **list)
{
	t_ac_list	*temp;

	if (!list)
		return ;
	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}
