/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:46:06 by jwilen            #+#    #+#             */
/*   Updated: 2019/11/12 07:39:33 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *needle, size_t l)
{
	char	*ptr;
	size_t	n_len;

	ptr = (char *)src;
	n_len = (size_t)ft_strlen(needle);
	if (needle[0] == '\0')
		return (ptr);
	while (*ptr && l-- >= n_len)
	{
		if (*ptr == *needle)
			if (ft_memcmp(needle, ptr, n_len) == 0)
				return ((char *)ptr);
		ptr++;
	}
	return (NULL);
}
