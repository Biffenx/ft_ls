/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:52:14 by jwilen            #+#    #+#             */
/*   Updated: 2019/10/23 11:00:05 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t s1size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	while (s1[i] != '\0')
		i++;
	res = 0;
	while (s2[res] != '\0')
		res++;
	if (s1size <= i)
		res = res + s1size;
	else
		res = res + i;
	j = 0;
	while (s2[j] != '\0' && i + 1 < s1size)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (res);
}
