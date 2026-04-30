/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ft_ps_medium.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:26:58 by varandri          #+#    #+#             */
/*   Updated: 2026/04/30 19:35:22 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back(t_list **stack_b, t_list **stack_a, t_ac_list **act_lst)
{
	t_list	*max_node;
	size_t	node_place;

	if (!stack_b || !*stack_b)
		return ;
	while (*stack_b)
	{
		max_node = ft_find_max_index(*stack_b);
		node_place = ft_find_node_place(*stack_b, max_node);
		if (node_place <= lst_size(*stack_b) / 2)
			rotate_up(node_place, stack_b, act_lst, "rb");
		else if (node_place > lst_size(*stack_b) / 2)
			rotate_down((lst_size(*stack_b) - node_place), stack_b,
				act_lst, "rrb");
		ft_push(stack_b, stack_a, act_lst, "pa");
	}
}

void	ft_ps_medium(t_list **stack_a, t_list **stack_b, t_ac_list **act_lst)
{
	size_t	min_index;
	size_t	rng_block;
	// size_t	n_block;

	index_attribution(stack_a);
	min_index = (ft_find_min_index(*stack_a))->index;
	rng_block = ft_range_block(*stack_a, ft_sqrt(lst_size(*stack_a)));
	// n_block = ft_sqrt(lst_size(*stack_a));
	if (lst_size(*stack_a) <= 5)
		return (ft_ps_few(stack_a, stack_b, act_lst));
	while (*stack_a)
	{
		if (*stack_a && !is_member_block(*stack_a, min_index, rng_block))
			min_index += rng_block + 1;
		while (*stack_a && !((*stack_a)->index >= (long)min_index
				&& (*stack_a)->index <= (long)(min_index + rng_block)))
			ft_rotate(stack_a, act_lst, "ra");
		if (!*stack_a)
			break ;
		ft_push(stack_a, stack_b, act_lst, "pb");
		if (stack_b && *stack_b && (*stack_b)->next
			&& (*stack_b)->index < ((*stack_b)->next)->index)
			ft_swap(stack_b, act_lst, "sb");
	}
	push_back(stack_b, stack_a, act_lst);
}
