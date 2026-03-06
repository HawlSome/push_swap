/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 05:10:53 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 19:54:26 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_flag_list	*flag;
	float		disorder;

	flag = lst_flag_last(*flags);
	disorder = disorder_metric(*stack_a);
	if (disorder < 1e-6)
		return ;
	if (!ft_strcmp(flag->algo_type, "adaptive"))
		ft_ps_adaptive(stack_a, stack_b, actions, &flag);
	else if (!ft_strcmp(flag->algo_type, "simple"))
		ft_ps_simple(stack_a, stack_b, actions);
	else if (!ft_strcmp(flag->algo_type, "medium"))
		ft_ps_medium(stack_a, stack_b, actions);
	else if (!ft_strcmp(flag->algo_type, "complex"))
		ft_ps_complex(stack_a, stack_b, actions);
}

static void	execute_bench(char **input, float disorder,
			t_ac_list *actions, t_flag_list *flags)
{
	if (ft_is_there_bench_flag(input))
		ft_benchmark(disorder, actions, flags);
}

static void	print_moves(t_ac_list *actions)
{
	while (actions)
	{
		ft_printf(1, "%s\n", actions->name);
		actions = actions->next;
	}
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
	if (!ft_is_there_complexity_flag(input))
	{
		new_flag(&flags, "adaptive", 1);
		if (disorder >= 1e-6)
			ft_ps_adaptive(stack_a, stack_b, actions, &flags);
		execute_bench(input, disorder, *actions, flags);
		print_moves(*actions);
		lst_flag_clear(&flags);
		return ;
	}
	get_flags(&flags, input);
	execute_flags(stack_a, stack_b, actions, &flags);
	execute_bench(input, disorder, *actions, flags);
	print_moves(*actions);
	lst_flag_clear(&flags);
}
