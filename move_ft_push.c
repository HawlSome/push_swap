/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:52:37 by varandri          #+#    #+#             */
/*   Updated: 2026/02/24 14:11:32 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **from, t_list **to, t_ac_list **act_lst, char *act_name)
{
	t_list	*node;

	if (!from || !*from)
		return ;
	if (act_name)
		new_action(act_lst, act_name);
	node = *from;
	*from = (*from)->next;
	node->next = NULL;
	lst_add_front(to, node);
}
