/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 15:55:07 by jwilen            #+#    #+#             */
/*   Updated: 2020/06/10 15:56:17 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_word_count(char *str)
{
	unsigned int	count;
	unsigned int	i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	if (ft_isspace(str[i]) != 1)
	{
		count++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) != 1 && ft_isspace(str[i - 1]) == 1)
			count++;
		i++;
	}
	return (count);
}
