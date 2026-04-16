/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_few.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:46:30 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 17:06:51 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_place_max(t_list	**stack_a, t_ac_list **actions)
{
	size_t	max_place;
	t_list	*max_node;

	if (!stack_a || !*stack_a)
		return ;
	max_node = ft_find_max_value(*stack_a);
	max_place = ft_find_node_place(*stack_a, max_node);
	if (!max_place)
		ft_rotate(stack_a, actions, "ra");
	if (max_place == 1)
		ft_rev_rotate(stack_a, actions, "rra");
}

void	ft_ps_few(t_list **stack_a, t_list **stack_b, t_ac_list **actions)
{
	size_t	size_a;
	size_t	min_place;
	t_list	*min;

	if (!stack_a || !*stack_a)
		return ;
	size_a = lst_size(*stack_a);
	while (size_a > 3)
	{
		min = ft_find_min_value(*stack_a);
		min_place = ft_find_node_place(*stack_a, min);
		if (min_place <= 2 && min_place)
			rotate_up(min_place, stack_a, actions, "ra");
		if (min_place > 2 && min_place)
			rotate_down((size_a - min_place), stack_a, actions, "rra");
		ft_push(stack_a, stack_b, actions, "pb");
		size_a--;
	}
	if (size_a == 3)
		ft_place_max(stack_a, actions);
	if ((*stack_a)->value > ((*stack_a)->next)->value)
		ft_swap(stack_a, actions, "sa");
	while (*stack_b)
		ft_push(stack_b, stack_a, actions, "pa");
}
