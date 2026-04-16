/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_flag_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 04:18:56 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 06:04:54 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flag_list	*lst_flag_new(char *algo_type)
{
	t_flag_list	*node;

	node = (t_flag_list *)malloc(sizeof(t_flag_list));
	if (!node)
		return (NULL);
	node->is_adaptive = 0;
	node->algo_type = algo_type;
	node->next = NULL ;
	return (node);
}

size_t	lst_flag_size(t_flag_list *list)
{
	t_flag_list	*node;
	size_t		i;

	node = list;
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

t_flag_list	*lst_flag_last(t_flag_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	lst_flag_add_back(t_flag_list **list, t_flag_list *node)
{
	t_flag_list	*last;

	if (!node || !list)
		return ;
	if (!*list)
	{
		*list = node;
		return ;
	}
	last = lst_flag_last(*list);
	last->next = node;
}

void	lst_flag_clear(t_flag_list **list)
{
	t_flag_list	*temp;

	if (!list)
		return ;
	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}
