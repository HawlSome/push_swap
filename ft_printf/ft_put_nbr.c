/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:42:05 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 06:08:25 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert(char *nb_str, long nb, int n_len)
{
	if (!nb_str)
		return ;
	if (nb < 0)
	{
		nb = -nb;
		nb_str[0] = '-';
	}
	while (nb)
	{
		nb_str[n_len - 1] = nb % 10 + '0';
		nb = nb / 10;
		n_len--;
	}
}

static int	ft_int_len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

int	ft_put_nbr(int fd, int nbr)
{
	long	nb;
	int		n_len;
	char	*nb_str;

	if (!nbr)
	{
		write(fd, "0", 1);
		return (1);
	}
	nb = (long)nbr;
	n_len = ft_int_len(nb);
	nb_str = (char *) malloc((n_len + 1) * sizeof(char));
	if (!nb_str)
		return (0);
	ft_convert(nb_str, nb, n_len);
	nb_str[n_len] = '\0';
	ft_put_str(fd, nb_str);
	free(nb_str);
	return (n_len);
}
