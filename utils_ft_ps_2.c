/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 02:52:48 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 20:36:23 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_complexity_flag(char *str)
{
	if (!ft_strcmp(str, "--adaptive")
		|| !ft_strcmp(str, "--simple")
		|| !ft_strcmp(str, "--medium")
		|| !ft_strcmp(str, "--complex"))
		return (1);
	return (0);
}

int	ft_is_there_complexity_flag(char **input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (!ft_strcmp(input[i], "--adaptive")
			|| !ft_strcmp(input[i], "--simple")
			|| !ft_strcmp(input[i], "--medium")
			|| !ft_strcmp(input[i], "--complex"))
			return (1);
		i++;
	}
	return (0);
}

void	new_flag(t_flag_list **list, char *algo_type, int is_adaptive)
{
	t_flag_list	*node;

	if (!algo_type)
		return ;
	node = lst_flag_new(algo_type);
	if (!node)
		return ;
	node->is_adaptive = is_adaptive;
	lst_flag_add_back(list, node);
}

int	ft_is_there_bench_flag(char **input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (!ft_strcmp(input[i], "--bench"))
			return (1);
		i++;
	}
	return (0);
}
