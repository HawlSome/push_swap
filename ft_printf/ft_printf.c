/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:50:02 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 01:50:28 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(int fd, char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'f')
		count = ft_put_float(fd, va_arg(args, double));
	if (c == 's')
		count = ft_put_str(fd, va_arg(args, char *));
	if (c == 'i' || c == 'd')
		count = ft_put_nbr(fd, va_arg(args, int));
	if (c == '%')
	{
		write(fd, "%", 1);
		count = 1 ;
	}
	return (count);
}

int	ft_printf(int fd, char *str, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			write(fd, &str[i], 1);
		if (str[i] == '%')
		{
			i++;
			check_flag(fd, str[i], args);
		}
		i ++;
	}
	return (0);
}
