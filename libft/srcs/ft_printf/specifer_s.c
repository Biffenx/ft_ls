/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifer_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:59:53 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 13:40:35 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void		str_h_uno(t_tab *dt, int len, char *str)
{
	if (!dt->pre)
		len = ft_strlen(str);
	if (!dt->w_i.mi)
	{
		insert_pad(dt, len);
		write(dt->fd, str, len);
	}
	if (dt->w_i.mi)
	{
		write(dt->fd, str, len);
		insert_pad(dt, len);
	}
	dt->len += len - 1;
}

void		specifer_s_alfa(t_tab *dt, char *str, int len)
{
	if (str == NULL && dt->pre_i.pre > 0)
	{
		len = (dt->pre_i.pre > 7) ? 6 : dt->pre_i.pre;
		str = ft_strdup("(null)");
	}
	else if (str == NULL && dt->pre && dt->pre_i.pre == 0)
		len = 0;
	else if (str == NULL)
	{
		len = (!dt->pre_i.pre) ? 6 : dt->pre_i.pre;
		str = ft_strdup("(null)");
		free(str);
	}
	else if (dt->pre_i.pre > (int)ft_strlen(str))
		len = ft_strlen(str);
	else if (dt->pre && dt->pre_i.pre == 0)
		len = 0;
	else if (dt->pre && dt->pre_i.pre > 0)
		len = (ft_strlen(str) > 0) ? dt->pre_i.pre : 0;
	str_h_uno(dt, len, str);
}

/*
**		Conversion %s for strings
*/

void		specifer_s(t_tab *dt)
{
	char	*str;
	int		len;

	asterix(dt);
	str = va_arg(dt->ap, char*);
	len = 0;
	if (dt->fr[dt->i] == 'S')
	{
		ft_toupper_str(str, len);
		dt->caps = 1;
	}
	specifer_s_alfa(dt, str, len);
}
