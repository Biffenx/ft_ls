/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:03:57 by mlindhol          #+#    #+#             */
/*   Updated: 2020/06/10 15:59:22 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_toupper_str(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else
			str[i] = str[i];
		i++;
	}
	return (str);
}
