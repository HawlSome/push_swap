/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:05:49 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 17:03:21 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(size_t counter, t_list **stack, t_ac_list **act_lst
			, char *action)
{
	while (counter)
	{
		ft_rotate(stack, act_lst, action);
		counter--;
	}
}

void	rotate_down(size_t counter, t_list **stack, t_ac_list **act_lst
			, char *action)
{
	while (counter)
	{
		ft_rev_rotate(stack, act_lst, action);
		counter--;
	}
}

int	ft_find_node_place(t_list *list, t_list	*node)
{
	int	i;

	if (!node)
		return (0);
	i = 0;
	while (list && list != node)
	{
		list = list->next;
		i ++;
	}
	return (i);
}

t_list	*ft_find_min_value(t_list *list)
{
	t_list	*node;
	t_list	*node_min;

	node = list;
	node_min = list;
	while (node)
	{
		if (node->value < node_min->value)
			node_min = node;
		node = node->next;
	}
	return (node_min);
}

t_list	*ft_find_max_value(t_list *list)
{
	t_list	*node;
	t_list	*node_max;

	node = list;
	node_max = list;
	while (node)
	{
		if (node->value > node_max->value)
			node_max = node;
		node = node->next;
	}
	return (node_max);
}
