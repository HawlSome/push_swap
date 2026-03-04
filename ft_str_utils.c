/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:47:15 by varandri          #+#    #+#             */
/*   Updated: 2026/03/05 01:39:22 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-(unsigned char)s2[0]);
	if (!s2)
		return ((unsigned char)s1[0]);
	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
		((unsigned char *)res)[i++] = (unsigned char)0;
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sb = (char *)ft_calloc ((len + 1), sizeof(char));
	if (!sb)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sb[i] = s[start + i];
		i ++;
	}
	return (sb);
}

void	ft_free_2d(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
