/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:36:08 by jwilen            #+#    #+#             */
/*   Updated: 2020/02/25 07:34:21 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;

	if (dst == src)
		return (dst);
	i = ft_strlen(src);
	dst = ft_memcpy(dst, src, (i + 1));
	return (dst);
}
