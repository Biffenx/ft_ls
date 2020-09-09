/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 08:58:02 by jwilen            #+#    #+#             */
/*   Updated: 2019/11/05 10:44:06 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*new;
	size_t		len;

	len = ft_strlen(s1) + 1;
	if (!(new = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	return (ft_memcpy(new, s1, len));
}
