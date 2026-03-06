/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:12:24 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 17:06:11 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_simple(t_list **stack_a, t_list **stack_b, t_ac_list **act_lst)
{
	size_t	min_index;
	t_list	*min;
	size_t	size_a;

	size_a = lst_size(*stack_a);
	if (size_a <= 5)
		return (ft_ps_few(stack_a, stack_b, act_lst));
	while (size_a > 2)
	{
		min = ft_find_min_value(*stack_a);
		min_index = ft_find_node_place(*stack_a, min);
		if (min_index <= size_a / 2 && min_index)
			rotate_up(min_index, stack_a, act_lst, "ra");
		else if (min_index > size_a / 2 && min_index)
			rotate_down((size_a - min_index), stack_a, act_lst, "rra");
		ft_push(stack_a, stack_b, act_lst, "pb");
		size_a--;
	}
	ft_ps_few(stack_a, stack_b, act_lst);
}
