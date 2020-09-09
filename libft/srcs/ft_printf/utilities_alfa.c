/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_alfa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 07:27:04 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 12:34:34 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

size_t		calc_width(t_tab *dt)
{
	size_t	w;
	int		j;

	w = 0;
	j = (dt->fr[dt->i] == '.') ? dt->i + 1 : dt->i;
	while (ft_isdigit(dt->fr[j]))
	{
		w++;
		j++;
	}
	return (w);
}

void		check_length_more_h(t_tab *dt)
{
	if (dt->fr[dt->i + 1] == 'h')
	{
		dt->flag_info.hh = 1;
		dt->i++;
	}
	else
		dt->flag_info.h = 1;
	dt->i++;
}

void		check_length_more_l(t_tab *dt)
{
	if (dt->fr[dt->i + 1] == 'l')
	{
		dt->flag_info.ll = 1;
		dt->i++;
	}
	else
		dt->flag_info.l = 1;
	dt->i++;
}

char		*zero_fill(char *str, int pre, int len)
{
	char	*str2;
	int		i;

	i = -1;
	if (!(str2 = (char*)malloc(sizeof(char) * pre + 1)))
		exit(1);
	while (++i < pre - len)
		str2[i] = '0';
	while (i < pre && *str)
	{
		str2[i] = *str;
		str++;
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char		calc(char *nbr, size_t k, t_tab *dt)
{
	while (ft_isdigit(dt->fr[dt->i + 1]))
	{
		nbr[k] = dt->fr[dt->i + 1];
		k++;
		dt->i++;
	}
	return (*nbr);
}
