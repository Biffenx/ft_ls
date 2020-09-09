/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:03:54 by jwilen            #+#    #+#             */
/*   Updated: 2020/06/10 16:03:59 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstappend(t_list **alst, t_list *new)
{
	t_list *list;

	if (alst != NULL)
	{
		if (*alst != NULL)
			*alst = new;
		else
		{
			list = *alst;
			while (list->next != NULL)
				list = list->next;
			list->next = new;
		}
	}
}
