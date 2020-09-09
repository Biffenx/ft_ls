/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:32:23 by jwilen            #+#    #+#             */
/*   Updated: 2019/10/24 13:32:21 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_istherewhitespaces(s[start]))
		start++;
	end = ft_strlen(s);
	while (ft_istherewhitespaces(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	return (ft_strsub(s, start, end - start));
}
