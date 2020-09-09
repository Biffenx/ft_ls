/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:58:01 by jwilen            #+#    #+#             */
/*   Updated: 2019/11/05 11:00:28 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	int		n_len;

	ptr = (char *)haystack;
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return (ptr);
	while (*ptr)
	{
		if (*ptr == *needle)
		{
			if (ft_strncmp(needle, ptr, n_len) == 0)
				return (ptr);
		}
		ptr++;
	}
	return (NULL);
}
