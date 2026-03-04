/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_verification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:57:26 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 02:03:22 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_clone_verification(char **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_is_str_int(tab[i]) && !ft_strcmp(tab[i], tab[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_sus_verification(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_is_str_int(tab[i]) && !ft_is_valid_flag(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_falg_no_elem_verification(char **tab)
{
	if (!ft_is_there_str_int(tab) && ft_is_there_valid_flag(tab))
		return (1);
	return (0);
}

static int	ft_flow_verification(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		if (ft_is_over_under_flow(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_input_verification(char **tab)
{
	if (!tab)
		return (0);
	if (!ft_flow_verification(tab))
		return (0);
	if (!ft_clone_verification(tab))
		return (0);
	if (!ft_sus_verification(tab))
		return (0);
	if (ft_falg_no_elem_verification(tab))
		return (0);
	return (1);
}
