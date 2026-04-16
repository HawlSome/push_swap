/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_medium_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:44:07 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/26 17:02:59 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_attribution(t_list **stack)
{
	t_list	*list;
	t_list	*min;
	long	index;
	size_t	stack_size;

	if (!stack || !*stack)
		return ;
	stack_size = lst_size(*stack);
	index = 0;
	while (index < (long)stack_size)
	{
		list = *stack;
		min = NULL;
		while (list)
		{
			if ((list->index == -1) && (!min || list->value <= min->value))
				min = list;
			list = list->next;
		}
		if (min)
			min->index = index;
		index ++;
	}
}

size_t	ft_range_block(t_list *stack, size_t n_block)
{
	size_t	min;
	size_t	max;
	size_t	range;

	if (!stack || !n_block)
		return (0);
	min = (ft_find_min_index(stack))->index;
	max = (ft_find_max_index(stack))->index;
	range = (max - min) / n_block;
	return (range);
}

int	is_member_block(t_list *list, size_t min_index, size_t rng_block)
{
	t_list	*node;
	int		i;

	if (!list)
		return (0);
	node = list;
	i = 0;
	while (node)
	{
		if (node->index >= (long)min_index
			&& node->index <= (long)(min_index + rng_block))
			i ++;
		node = node->next;
	}
	return (i);
}
