/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:12:14 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/21 15:36:53 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	*free_tab(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(tab[size]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	col;
	size_t	start;
	size_t	i;

	tab = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	col = 0;
	i = 0;
	while (s[i])
	{
		i += ft_skipchar(&s[i], c);
		start = i;
		i += ft_reachchar(&s[i], c);
		if (start == i)
			break ;
		tab[col] = ft_substr(s, start, i - start);
		if (!tab[col])
			return (free_tab(tab, col));
		col++;
	}
	tab[col] = 0;
	return (tab);
}
