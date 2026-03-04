/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:51:55 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 01:48:03 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(int fd, char *str, ...);
int	ft_put_str(int fd, char *str);
int	ft_put_nbr(int fd, int nbr);
int	ft_put_float(int fd, float nb);

#endif