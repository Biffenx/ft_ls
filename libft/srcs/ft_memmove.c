/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:51:52 by amurtone          #+#    #+#             */
/*   Updated: 2020/02/25 07:35:15 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!len || dst == src)
		return (dst);
	d = (unsigned char *)dst + (len - 1);
	s = (unsigned char *)src + (len - 1);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
