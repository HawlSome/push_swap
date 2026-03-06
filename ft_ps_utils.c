/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 00:15:25 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 16:57:37 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_action(t_ac_list **list, char *name)
{
	t_ac_list	*node;

	if (!name)
		return ;
	node = lst_ac_new(name);
	if (!node)
		return ;
	lst_ac_add_back(list, node);
}

void	new_list_value(t_list **list, int value)
{
	t_list	*node;

	node = lst_new(value);
	if (!node)
		return ;
	lst_add_back(list, node);
}

size_t	ft_sqrt(size_t nb)
{
	size_t	i;

	i = 0;
	while (i * i < nb && i <= 46340)
		i++;
	if (i * i > nb)
		i --;
	if (i * i <= nb)
		return (i);
	return (0);
}

t_list	*ft_find_max_index(t_list *list)
{
	t_list	*max;

	max = list;
	while (list)
	{
		if (max->index <= list->index)
			max = list;
		list = list->next;
	}
	return (max);
}

t_list	*ft_find_min_index(t_list *list)
{
	t_list	*min;

	min = list;
	while (list)
	{
		if (min->index >= list->index)
			min = list;
		list = list->next;
	}
	return (min);
}
