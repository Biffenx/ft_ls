/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:21:33 by jwilen            #+#    #+#             */
/*   Updated: 2019/10/18 11:36:57 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occ;

	last_occ = 0;
	while (*s)
	{
		if (*s == c)
			last_occ = (char*)s;
		s++;
	}
	if (last_occ)
		return (last_occ);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
