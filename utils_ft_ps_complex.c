/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_complex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:18:22 by tokyrand          #+#    #+#             */
/*   Updated: 2026/02/27 23:26:23 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_max_bit(t_list *stack_a)
{
	t_list	*node;
	size_t	max;
	size_t	i;

	node = ft_find_max_index(stack_a);
	max = node->index;
	i = 0;
	while (max)
	{
		max = max >> 1;
		i ++;
	}
	return (i);
}
