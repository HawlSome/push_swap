/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:37:28 by varandri          #+#    #+#             */
/*   Updated: 2026/02/27 19:51:40 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_metric(t_list *stack_a)
{
	size_t	mistake;
	size_t	total_pairs;
	t_list	*node;
	t_list	*node_next;

	if (!stack_a)
		return (0);
	node = stack_a;
	mistake = 0;
	total_pairs = 0;
	while (node)
	{
		node_next = node->next;
		while (node_next)
		{
			total_pairs++;
			if (node->value > node_next->value)
				mistake++;
			node_next = node_next->next;
		}
		node = node->next;
	}
	if (!total_pairs)
		return ((float)0);
	return ((float)mistake / (float)total_pairs);
}
