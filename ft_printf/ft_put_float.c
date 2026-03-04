/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:42:01 by varandri          #+#    #+#             */
/*   Updated: 2026/03/04 16:43:00 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_float(int fd, float nb)
{
	long	dec;
	int		len;

	dec = (long)nb;
	len = 0;
	len += ft_put_nbr(fd, dec);
	len += ft_put_str(fd, ".");
	dec = (long)(nb * 100) % 100;
	len += ft_put_nbr(fd, (int)dec);
	if (dec < 10)
		len += ft_put_str(fd, "0");
	return (len);
}
