/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:33:29 by jwilen            #+#    #+#             */
/*   Updated: 2020/08/15 10:00:02 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_getintlen(uintmax_t n)
{
	size_t	i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		++i;
	}
	return (i);
}
