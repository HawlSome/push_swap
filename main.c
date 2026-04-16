/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 02:07:43 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 17:39:39 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char		**input;
	t_list		*stack_a;
	t_list		*stack_b;
	t_ac_list	*actions;

	stack_a = NULL;
	stack_b = NULL;
	actions = NULL;
	if (!ft_parse_input(argc, argv, &stack_a, &input))
		return (0);
	push_swap(input, &stack_a, &stack_b, &actions);
	ft_free_2d(input);
	lst_clear(&stack_a);
	lst_clear(&stack_b);
	lst_ac_clear(&actions);
	return (0);
}
