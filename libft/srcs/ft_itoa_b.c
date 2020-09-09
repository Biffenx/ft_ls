/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 07:53:17 by jwilen            #+#    #+#             */
/*   Updated: 2020/02/21 00:58:58 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		n_len(uintmax_t nbr, int base)
{
	int			len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_b(uintmax_t n, int base)
{
	char		*str;
	char		*ter;
	uintmax_t	len;
	uintmax_t	nbr;

	nbr = (n < 0 && base == 10) ? -n : (uintmax_t)n;
	len = (n == 0 || (n < 0 && base == 10)) ? 1 : 0;
	len += n_len(nbr, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ter = ft_strdup("0123456789abcdef");
	if (n < 0 && base == 10)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	nbr = (n < 0 && base == 10) ? -n : (uintmax_t)n;
	while (nbr != 0)
	{
		str[--len] = ter[nbr % base];
		nbr /= base;
	}
	free(ter);
	return (str);
}
