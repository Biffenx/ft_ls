/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_x_delta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:48:16 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:34:26 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void		c_x_xi(t_tab *dt, char *ltr, char *str, unsigned int len)
{
	if (dt->wi && dt->w_i.h_tag)
	{
		write(dt->fd, ltr, 2);
		dt->len += 2;
		insert_pad(dt, ft_strlen(str) + 2);
	}
	if (dt->wi)
	{
		if (dt->w_i.h_tag)
			insert_pad(dt, ft_strlen(str) + dt->wi);
		else
			insert_pad(dt, ft_strlen(str) + dt->wi);
	}
	if (!dt->wi && dt->w_i.h_tag)
	{
		write(dt->fd, ltr, 2);
		dt->len += 2;
		write(dt->fd, str, len);
	}
	else
		write(dt->fd, str, len);
}

void		c_x_pi(t_tab *dt, char *ltr, char *str, unsigned int len)
{
	if (dt->wi)
	{
		if (dt->w_i.h_tag)
			insert_pad(dt, ft_strlen(str) + 2);
		else
			insert_pad(dt, ft_strlen(str));
	}
	if (dt->w_i.h_tag)
	{
		write(dt->fd, ltr, 2);
		dt->len += 2;
		write(dt->fd, str, len);
	}
	else
		write(dt->fd, str, len);
}
