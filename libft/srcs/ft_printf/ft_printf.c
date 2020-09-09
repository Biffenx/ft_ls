/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:59:13 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:40:22 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

/*
**		Function to work with wildcards
*/

void		asterix(t_tab *dt)
{
	if (dt->w_asterix == 1)
	{
		dt->wi = va_arg(dt->ap, int);
		if (dt->wi < 0)
		{
			dt->neg = 1;
			dt->wi = ft_abs(dt->wi);
		}
	}
	if (dt->p_asterix == 1)
	{
		dt->pre_i.pre = va_arg(dt->ap, int);
		if (dt->pre_i.pre < 0)
		{
			dt->neg = 1;
			dt->pre_i.pre = ft_abs(dt->wi);
		}
	}
}

/*
**		Initialazing the switches to zeros
*/

void		initialz(t_tab *dt)
{
	dt->w_i.h_tag = 0;
	dt->w_i.zero = 0;
	dt->w_i.mi = 0;
	dt->w_i.pl = 0;
	dt->w_i.sp = 0;
	dt->wi = 0;
	dt->neg = 0;
	dt->p_asterix = 0;
	dt->w_asterix = 0;
	dt->flag_info.hh = 0;
	dt->flag_info.h = 0;
	dt->flag_info.ll = 0;
	dt->flag_info.l = 0;
	dt->flag_info.ld = 0;
	dt->flag_info.j = 0;
	dt->flag_info.z = 0;
	dt->pre = 0;
	dt->pre_i.pre = 0;
	dt->caps = 0;
	dt->hash = 0;
	dt->zero = 0;
	dt->nbr = 0;
}

/*
**		Function to decide what FD to use
*/

int			ft_dprintf(int fd, const char *format, ...)
{
	t_tab	*dt;
	int		ret;

	if (!(dt = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	dt->fd = fd;
	dt->fr = (char *)format;
	if (format)
	{
		va_start(dt->ap, format);
		dt->len = 0;
		initialz(dt);
		parse_format(dt);
		va_end(dt->ap);
	}
	ret = dt->len;
	free(dt);
	return (ret);
}

/*
**		The main FT_PRINTF function
*/

int			ft_printf(const char *format, ...)
{
	t_tab	*dt;
	int		ret;

	if (!(dt = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	dt->fd = 1;
	dt->fr = (char *)format;
	if (format)
	{
		va_start(dt->ap, format);
		dt->len = 0;
		initialz(dt);
		parse_format(dt);
		va_end(dt->ap);
	}
	ret = dt->len;
	free(dt);
	return (ret);
}
