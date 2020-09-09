/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 09:29:43 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:32:57 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		Inserting padding for bits
*/

void		insert_bit_pad(t_tab *dt, char c, int len)
{
	int		k;

	k = 0;
	if (dt->wi > len)
		while (k++ < (dt->wi - len))
			write(dt->fd, &c, 1);
}

void		put_bit(t_tab *dt, char *str, int len)
{
	if (!dt->neg)
	{
		dt->pre == 0 && dt->w_i.zero ?
		insert_bit_pad(dt, '0', len) : insert_bit_pad(dt, ' ', len);
		while (*str)
			write(dt->fd, str++, 1);
	}
	else
	{
		while (*str)
			write(dt->fd, str++, 1);
		insert_bit_pad(dt, ' ', len);
	}
}

/*
**		Conversion %b for bits
*/

void		specifer_b(t_tab *dt)
{
	uintmax_t		num;
	int				len;
	char			*bit;
	char			*bit_ptr;

	asterix(dt);
	num = check_flag_unsigned(dt);
	bit = ft_itoa_b(num, 2);
	len = ft_strlen(bit);
	if (dt->pre_i.pre && dt->pre > len)
	{
		bit_ptr = zero_fill(bit, dt->pre_i.pre, len);
		free(bit);
		bit = ft_strdup(bit_ptr);
		free(bit_ptr);
		len = ft_strlen(bit);
	}
	put_bit(dt, bit, len);
	free(bit);
}
