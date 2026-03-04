/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:28:52 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 00:39:25 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_total_len(size_t size, char **str, char *sep)
{
	size_t	i;
	size_t	s_len;
	size_t	sep_len;

	i = 0;
	s_len = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		s_len += ft_strlen(str[i]);
		if (i != size - 1)
			s_len += sep_len;
		i++;
	}
	s_len++;
	return (s_len);
}

static void	ft_insert_sep(char **j_str, char *sep, size_t *k)
{
	size_t	i;

	i = 0;
	while (sep[i])
	{
		(*j_str)[*k] = sep[i];
		i++;
		*k = *k + 1;
	}
}

static void	ft_fill_j_str(size_t size, char **strs, char **j_str, char *sep)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (j < ft_strlen(strs[i]))
		{
			(*j_str)[k] = strs[i][j];
			j++;
			k++;
		}
		if (i != (size -1))
			ft_insert_sep(j_str, sep, &k);
		i++;
	}
}

char	*ft_strjoin(size_t size, char **strs, char *sep)
{
	char	*j_str;

	if (!sep)
		return (NULL);
	j_str = (char *)ft_calloc(ft_total_len(size, strs, sep), sizeof (char));
	if (!j_str)
		return (NULL);
	ft_fill_j_str(size, strs, &j_str, sep);
	return (j_str);
}
