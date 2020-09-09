/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:16:02 by jwilen            #+#    #+#             */
/*   Updated: 2019/10/23 14:53:45 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s2;

	if (!s || !(s2 = (char **)malloc(sizeof(*s2) *
					(ft_countwords(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if (!(s2[i] = ft_strnew(ft_wordlength(&s[j], c) + 1)))
			s2 = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			s2[i][k++] = s[j++];
		s2[i][k] = '\0';
	}
	s2[i] = 0;
	return (s2);
}
