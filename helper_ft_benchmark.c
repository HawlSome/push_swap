/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:54:22 by varandri          #+#    #+#             */
/*   Updated: 2026/03/08 08:01:10 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_actions(t_ac_list *actions, char *action_name)
{
	int	count;

	if (!actions || !action_name)
		return (0);
	count = 0;
	while (actions)
	{
		if (!ft_strcmp(action_name, actions->name))
			count++;
		actions = actions->next;
	}
	return (count);
}

static void	ft_print_strategy(int is_adaptive, char *algo_type)
{
	if (is_adaptive)
	{
		ft_printf(2, "Adaptive / ");
		if (!ft_strcmp(algo_type, "simple")
			|| !ft_strcmp(algo_type, "adaptive"))
			ft_printf(2, "O(n^2)\n");
		if (!ft_strcmp(algo_type, "medium"))
			ft_printf(2, "O(n√n)\n");
		if (!ft_strcmp(algo_type, "complex"))
			ft_printf(2, "O(nlogn)\n");
	}
	else if (!ft_strcmp(algo_type, "simple"))
		ft_printf(2, "Simple / O(n^2)\n");
	else if (!ft_strcmp(algo_type, "medium"))
		ft_printf(2, "Medium / O(n√n)\n");
	else if (!ft_strcmp(algo_type, "complex"))
		ft_printf(2, "Complex / O(nlogn)\n");
}

void	ft_benchmark(float disorder, t_ac_list *actions, t_flag_list *flags)
{
	t_flag_list	*last_flag;

	if (!flags)
		return ;
	last_flag = lst_flag_last(flags);
	ft_printf(2, "[bench] disorder:\t%f%%\n", (float)(disorder * 100));
	ft_printf(2, "[bench] strategy:\t");
	ft_print_strategy(last_flag->is_adaptive, last_flag->algo_type);
	ft_printf(2, "[bench] total_ops:\t%i\n", (int)lst_ac_size(actions));
	ft_printf(2, "[bench] sa:\t%i\t", ft_count_actions(actions, "sa"));
	ft_printf(2, "sb:\t%i\t", ft_count_actions(actions, "sb"));
	ft_printf(2, "pa:\t%i\t", ft_count_actions(actions, "pa"));
	ft_printf(2, "ss:\t%i\t", ft_count_actions(actions, "ss"));
	ft_printf(2, "pb:\t%i\n", ft_count_actions(actions, "pb"));
	ft_printf(2, "[bench] ra:\t%i\t", ft_count_actions(actions, "ra"));
	ft_printf(2, "rb:\t%i\t", ft_count_actions(actions, "rb"));
	ft_printf(2, "rr:\t%i\t", ft_count_actions(actions, "rr"));
	ft_printf(2, "rra:\t%i\t", ft_count_actions(actions, "rra"));
	ft_printf(2, "rrb:\t%i\t", ft_count_actions(actions, "rrb"));
	ft_printf(2, "rrr:\t%i\n", ft_count_actions(actions, "rrr"));
}
