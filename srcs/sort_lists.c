/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:19:39 by jwilen            #+#    #+#             */
/*   Updated: 2020/09/07 06:02:26 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_data	*sort_rev(t_data *lst)
{
	t_data		*prev_node;
	t_data		*cur_node;

	if (lst != NULL)
	{
		prev_node = lst;
		cur_node = lst->next;
		lst = lst->next;
		prev_node->next = NULL;
		while (lst != NULL)
		{
			lst = lst->next;
			cur_node->next = prev_node;
			prev_node = cur_node;
			cur_node = lst;
		}
		lst = prev_node;
	}
	return (lst);
}

static t_data	*sorted_merge_time(t_data *a, t_data *b, t_base *base)
{
	t_data		*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->m_time > b->m_time)
		result = a;
	else if (a->m_time == b->m_time)
	{
		if (ft_strcmp(a->name, b->name) < 0)
			result = a;
		else
			result = b;
	}
	else
		result = b;
	if (result == a)
		result->next = sorted_merge_time(a->next, b, base);
	else
		result->next = sorted_merge_time(a, b->next, base);
	return (result);
}

void			front_back_split(t_data *src, t_data **f_ref, t_data **b_ref)
{
	t_data		*fast;
	t_data		*slow;

	slow = src;
	fast = src->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*f_ref = src;
	*b_ref = slow->next;
	slow->next = NULL;
}

static t_data	*merge_sort_time(t_data **files, t_base *base)
{
	t_data		*head;
	t_data		*a;
	t_data		*b;

	head = *files;
	if ((head == NULL) || (head->next == NULL))
		return (*files);
	front_back_split(head, &a, &b);
	merge_sort_time(&a, base);
	merge_sort_time(&b, base);
	*files = sorted_merge_time(a, b, base);
	return (*files);
}

t_data			*sort(t_base *base, t_data *lst)
{
	t_options		*current;

	current = base->options;
	current->t == true ? (lst = merge_sort_time(&lst, base)) : 0;
	current->cap_s == true ? (lst) = merge_sort_size(&lst, base) : 0;
	current->r == true ? (lst = sort_rev(lst)) : 0;
	return (lst);
}
