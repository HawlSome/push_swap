/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_adaptive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:26:22 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 22:16:26 by tokyrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_adaptive(t_list **stack_a, t_list **stack_b,
	t_ac_list **act_list, t_flag_list **flags)
{
	float		disorder;

	disorder = disorder_metric(*stack_a);
	if (disorder < 0.2f)
	{
		ft_ps_simple(stack_a, stack_b, act_list);
		(*flags)->algo_type = "simple";
	}
	else if (disorder >= 0.2f && disorder <= 0.5f)
	{
		ft_ps_medium(stack_a, stack_b, act_list);
		(*flags)->algo_type = "medium";
	}
	else
	{
		ft_ps_complex(stack_a, stack_b, act_list);
		(*flags)->algo_type = "complex";
	}
	return ;
}
