/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_verification_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:56:52 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 01:36:16 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_flag(char *str)
{
	int	res;

	res = 0;
	if (!ft_strcmp(str, "--adaptive"))
		res = 1;
	if (!ft_strcmp(str, "--simple"))
		res = 1;
	if (!ft_strcmp(str, "--medium"))
		res = 1;
	if (!ft_strcmp(str, "--complex"))
		res = 1;
	if (!ft_strcmp(str, "--bench"))
		res = 1;
	return (res);
}

int	ft_is_there_valid_flag(char **tab)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (ft_is_valid_flag(tab[i]))
			count++;
		i++;
	}
	if (count)
		return (1);
	return (0);
}

int	ft_is_str_int(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i ++;
	if (str[i] && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

int	ft_is_there_str_int(char **tab)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (ft_is_str_int(tab[i]))
			count++;
		i++;
	}
	if (count)
		return (1);
	return (0);
}

int	ft_is_over_under_flow(char *tab)
{
	int			i;
	int			sign;
	long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (tab[i] == 32 || (tab[i] >= 9 && tab[i] <= 13))
		i ++;
	if (tab[i] == '-' || tab[i] == '+')
	{
		if (tab[i] == '-')
			sign = -sign;
		i ++;
	}
	while (ft_isdigit(tab[i]))
	{
		nbr = nbr * 10 + (tab[i] - '0');
		if (sign == 1 && nbr > 2147483647LL)
			return (1);
		if (sign == -1 && nbr > 2147483648LL)
			return (1);
		i ++;
	}
	return (0);
}
