/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 05:10:53 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 06:31:54 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reinitialize_list(t_list **stack_a, t_list *backup_a,
			t_ac_list **actions)
{
	lst_clear(stack_a);
	*stack_a = lst_dup(backup_a);
	lst_ac_clear(actions);
	*actions = NULL;
}

static void	get_flags(t_flag_list **flags, char **input)
{
	size_t		i;

	i = 0;
	while (input[i])
	{
		if (ft_is_valid_flag(input[i]))
		{
			if (!ft_strcmp(input[i], "--adaptive"))
				new_flag(flags, "adaptive", 1);
			if (!ft_strcmp(input[i], "--simple"))
				new_flag(flags, "simple", 0);
			if (!ft_strcmp(input[i], "--medium"))
				new_flag(flags, "medium", 0);
			if (!ft_strcmp(input[i], "--complex"))
				new_flag(flags, "complex", 0);
		}
		i++;
	}
}

static void	execute_flags(t_list	**stack_a, t_list **stack_b,
			t_ac_list **actions, t_flag_list **flags)
{
	t_list		*backup_a;
	t_flag_list	*flag;

	backup_a = lst_dup(*stack_a);
	flag = *flags;
	while (flag)
	{
		reinitialize_list(stack_a, backup_a, actions);
		if (!ft_strcmp(flag->algo_type, "adaptive"))
			ft_ps_adaptive(stack_a, stack_b, actions, flags);
		if (!ft_strcmp(flag->algo_type, "simple"))
			ft_ps_simple(stack_a, stack_b, actions);
		if (!ft_strcmp(flag->algo_type, "medium"))
			ft_ps_medium(stack_a, stack_b, actions);
		if (!ft_strcmp(flag->algo_type, "complex"))
			ft_ps_complex(stack_a, stack_b, actions);
		flag = flag->next;
	}
	lst_clear(&backup_a);
}

static void	execute_bench(char **input, float disorder,
			t_ac_list *actions, t_flag_list *flags)
{
	if (ft_is_there_bench_flag(input))
		ft_benchmark(disorder, actions, flags);
}

void	push_swap(char **input, t_list **stack_a, t_list **stack_b,
			t_ac_list **actions)
{
	t_flag_list	*flags;
	float		disorder;

	if (!stack_a || !*stack_a || !input || !*input)
		return ;
	flags = NULL;
	disorder = disorder_metric(*stack_a);
	if (disorder < 1e-6)
		return ;
	if (!ft_is_there_complexity_flag(input))
	{
		new_flag(&flags, "adaptive", 1);
		ft_ps_adaptive(stack_a, stack_b, actions, &flags);
		execute_bench(input, disorder, *actions, flags);
		lst_flag_clear(&flags);
		return ;
	}
	get_flags(&flags, input);
	execute_flags(stack_a, stack_b, actions, &flags);
	execute_bench(input, disorder, *actions, flags);
	lst_flag_clear(&flags);
}
