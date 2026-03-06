/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:57:29 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 16:22:00 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack_a(t_list **stack_a, char **sp_str)
{
	size_t	i;

	if (!sp_str || !*sp_str)
		return ;
	i = 0;
	while (sp_str[i])
	{
		if (ft_is_str_int(sp_str[i]))
			new_list_value(stack_a, ft_atoi(sp_str[i]));
		i++;
	}
}

int	ft_parse_input(int argc, char **argv, t_list **stack_a, char ***parsed)
{
	char	*jnd_str;
	char	**sp_str;

	if (argc <= 1)
		return (0);
	jnd_str = ft_strjoin((size_t)(argc - 1), argv + 1, " ");
	if (!jnd_str)
	{
		ft_printf(2, "Error\n");
		return (0);
	}
	sp_str = ft_split(jnd_str, ' ');
	free(jnd_str);
	if (!sp_str || !ft_input_verification(sp_str))
	{
		ft_printf(2, "Error\n");
		ft_free_2d(sp_str);
		return (0);
	}
	*parsed = sp_str;
	fill_stack_a(stack_a, sp_str);
	return (1);
}
