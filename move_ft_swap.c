/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:51:40 by varandri          #+#    #+#             */
/*   Updated: 2026/02/21 00:37:16 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, t_ac_list **act_lst, char *act_name)
{
	t_list	*sec_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if (act_name)
		new_action(act_lst, act_name);
	sec_node = (*stack)->next;
	(*stack)->next = sec_node->next;
	sec_node->next = *stack;
	*stack = sec_node;
}

void	ft_s_swap(t_list **stack_a, t_list **stack_b, t_ac_list **act_lst)
{
	new_action(act_lst, "ss");
	ft_swap(stack_a, NULL, NULL);
	ft_swap(stack_b, NULL, NULL);
}
