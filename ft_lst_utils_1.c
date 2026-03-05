/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:30:27 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 06:02:25 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear(t_list **list)
{
	t_list	*temp;

	if (!list)
		return ;
	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

t_list	*lst_dup(t_list *stack)
{
	t_list	*new;
	t_list	*node;
	t_list	*current;

	if (!stack)
		return (NULL);
	new = NULL;
	current = stack;
	while (current)
	{
		node = lst_new(current->value);
		if (!node)
		{
			lst_clear(&new);
			return (NULL);
		}
		lst_add_back(&new, node);
		current = current->next;
	}
	return (new);
}
