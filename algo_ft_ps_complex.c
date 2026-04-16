/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:18:27 by varandri          #+#    #+#             */
/*   Updated: 2026/02/27 23:26:08 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_by_bit(t_list **stack_a, t_list **stack_b,
	t_ac_list **act_lst, size_t i)
{
	size_t	size_a;	
	size_t	bit;

	size_a = lst_size(*stack_a);
	while (size_a)
	{
		bit = ((*stack_a)->index) >> i & 1;
		if (bit)
			ft_rotate(stack_a, act_lst, "ra");
		else
			ft_push(stack_a, stack_b, act_lst, "pb");
		size_a--;
	}
}

void	ft_ps_complex(t_list **stack_a, t_list **stack_b, t_ac_list **act_lst)
{
	size_t	max_bit_count;
	size_t	i;

	if (lst_size(*stack_a) <= 5)
		return (ft_ps_few(stack_a, stack_b, act_lst));
	index_attribution(stack_a);
	max_bit_count = ft_max_bit(*stack_a);
	i = 0;
	while (i < max_bit_count)
	{
		ft_sort_by_bit(stack_a, stack_b, act_lst, i);
		while (*stack_b)
			ft_push(stack_b, stack_a, act_lst, "pa");
		i ++;
	}
	return ;
}
