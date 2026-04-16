/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:01:36 by varandri          #+#    #+#             */
/*   Updated: 2026/02/21 00:37:16 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **stack, t_ac_list **act_lst, char *act_name)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (act_name)
		new_action(act_lst, act_name);
	first = *stack;
	last = lst_last(*stack);
	last->next = first;
	while (first && first->next && first->next != last)
		first = first->next;
	first->next = NULL;
	*stack = last;
}

void	ft_r_rev_rotate(t_list **stack_a, t_list **stack_b, t_ac_list **act_lst)
{
	new_action(act_lst, "rrr");
	ft_rev_rotate(stack_a, NULL, NULL);
	ft_rev_rotate(stack_b, NULL, NULL);
}
