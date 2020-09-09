/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:05:45 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:33:51 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void		put_padd(t_tab *dt, char c, int len)
{
	int		i;

	i = 0;
	if (dt->wi > len)
		while (i++ < dt->wi - len)
			write(dt->fd, &c, 1);
}

void		put_ptr(t_tab *dt, char *str, int len)
{
	put_padd(dt, ' ', len);
	write(dt->fd, "0x", 2);
	while (*str)
		write(dt->fd, str++, 1);
	if (dt->wi >= dt->pre_i.pre + 2 || dt->wi >= len)
		dt->len += (dt->wi > len) ? dt->wi : len;
	else if (dt->pre_i.pre >= len - 2)
		dt->len += dt->pre_i.pre + 2;
	else
		dt->len += len;
}

void		put_ptr_min(t_tab *dt, char *str, int len)
{
	write(dt->fd, "0x", 2);
	while (*str)
		write(dt->fd, str++, 1);
	put_padd(dt, ' ', len);
	if (dt->wi >= dt->pre_i.pre + 2 || dt->wi >= len)
		dt->len += (dt->wi > len) ? dt->wi : len;
	else if (dt->pre_i.pre >= len - 2)
		dt->len += dt->pre_i.pre + 2;
	else
		dt->len += len;
}

void		c_p_alfa(t_tab *dt, char *ptr, char *ptr_p, unsigned int len)
{
	ptr_p = zero_fill(ptr, dt->pre_i.pre, len);
	free(ptr);
	ptr = ft_strdup(ptr_p);
	free(ptr_p);
	len = ft_strlen(ptr);
}

/*
**		Conversion %p for pointers
*/

void		specifer_p(t_tab *dt)
{
	uintmax_t		pt;
	unsigned int	len;
	char			*ptr;
	char			*ptr_p;

	asterix(dt);
	pt = va_arg(dt->ap, uintmax_t);
	ptr_p = NULL;
	if (pt == 0 && dt->pre && dt->pre_i.pre == 0)
	{
		write(dt->fd, "0x", 2);
		dt->len += 1;
		return ;
	}
	ptr = ft_itoa_b(pt, 16);
	len = ft_strlen(ptr);
	if (dt->pre && dt->pre_i.pre > (int)len)
		c_p_alfa(dt, ptr, ptr_p, len);
	dt->w_i.mi == 0 ? put_ptr(dt, ptr, len + 2) : put_ptr_min(dt, ptr, len + 2);
	dt->len += -1;
	free(ptr);
}
