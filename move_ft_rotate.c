/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:56:26 by varandri          #+#    #+#             */
/*   Updated: 2026/02/27 23:22:09 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, t_ac_list **act_lst, char *act_name)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (act_name)
		new_action(act_lst, act_name);
	first = *stack;
	(*stack) = (*stack)->next;
	last = lst_last(*stack);
	first->next = NULL;
	last->next = first;
}

void	ft_r_rotate(t_list **stack_a, t_list **stack_b, t_ac_list **act_lst)
{
	new_action(act_lst, "rr");
	ft_rotate(stack_a, NULL, NULL);
	ft_rotate(stack_b, NULL, NULL);
}
