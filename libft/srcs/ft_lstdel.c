/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:30:35 by jwilen            #+#    #+#             */
/*   Updated: 2020/07/28 10:19:00 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next != NULL)
	{
		ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(alst, del);
	}
	else
		ft_lstdelone(alst, del);
}
