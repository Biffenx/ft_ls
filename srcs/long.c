/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:46:21 by jwilen            #+#    #+#             */
/*   Updated: 2020/09/06 20:45:27 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		print_time(t_data *current, t_base *base)
{
	time_t		today;

	today = time(NULL);
	if (today == ((time_t)-1))
	{
		ft_printf("Failure to obtain the current time.\n");
		exit(EXIT_FAILURE);
	}
	if (base->options->cap_t == false)
	{
		if ((today - current->m_time) <= 15778800)
			ft_printf(" %.12s ", ctime(&current->m_time) + 4);
		else
		{
			ft_printf(" %.7s ", ctime(&current->m_time));
			ft_printf("%.*s ", 4, (ctime(&current->m_time) + 4) + 16);
		}
	}
	else
		ft_printf(" %.20s ", ctime(&current->m_time) + 4);
}

static void		flag_o(t_base *base, t_data *current, int w[7])
{
	if (base->options->n == true)
		ft_printf("%d", current->st_gid_nbr);
	else
		ft_printf("  %-*s", w[3], current->st_gid_grname);
}

static void		print_long_beta(t_base *base, t_data *current, int w[7])
{
	char		buff[NAME_MAX + 1];

	if ((get_file_mode(current->st_mode) != 'b') &&
		(get_file_mode(current->st_mode) != 'c'))
		ft_printf("  %*lld", w[4], current->st_size);
	else
	{
		ft_printf(" %*d", w[5], major(current->dev_t));
		ft_printf(", %*d", w[6], minor(current->dev_t));
	}
	print_time(current, base);
	if (get_file_mode(current->st_mode) != 'l')
		ft_strchr(current->name, '/') ? ft_printf("%s\n",
		ft_strrchr(current->name, '/') + 1) : ft_printf("%s\n", current->name);
	else
	{
		ft_bzero(buff, NAME_MAX + 1);
		readlink(current->name, buff, NAME_MAX);
		ft_printf("%s -> %s\n", ft_strrchr(current->name, '/') + 1, buff);
	}
}

static void		print_long_alfa(t_base *base, t_data *current, int w[7])
{
	if (current->st_mode & S_ISGID)
		(!(current->st_mode & S_IXGRP) ? ft_printf("S") : ft_printf("s"));
	else
		ft_printf((current->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((current->st_mode & S_IROTH) ? "r" : "-");
	ft_printf((current->st_mode & S_IWOTH) ? "w" : "-");
	if (current->st_mode & S_ISVTX)
		(!(current->st_mode & S_IXOTH) ? ft_printf("T") : ft_printf("t"));
	else
		ft_printf((current->st_mode & S_IXOTH) ? "x" : "-");
	ft_printf("%c", file_acl(current->name));
	ft_printf(" %*hu", w[1], current->st_nlink);
	base->options->n == true ? ft_printf(" %d ", current->st_uid_nbr) :
	ft_printf(" %-*s", w[2], current->st_uid_pwname);
	base->options->o == true ? 0 : flag_o(base, current, w);
	print_long_beta(base, current, w);
}

void			print_long(t_base *base, t_data *lst)
{
	t_data		*current;
	int			w[7];

	current = lst;
	ft_bzero(w, sizeof(w));
	width_clmn(current, w);
	lst == base->files ? 0 : ft_printf("total %d\n", w[0]);
	while (current)
	{
		base->options->i == true ? ft_printf("%d ", current->st_ino) : 0;
		ft_printf("%c", get_file_mode(current->st_mode));
		ft_printf((current->st_mode & S_IRUSR) ? "r" : "-");
		ft_printf((current->st_mode & S_IWUSR) ? "w" : "-");
		if (current->st_mode & S_ISUID)
			(!(current->st_mode & S_IXUSR) ? ft_printf("S") : ft_printf("s"));
		else
			ft_printf((current->st_mode & S_IXUSR) ? "x" : "-");
		ft_printf((current->st_mode & S_IRGRP) ? "r" : "-");
		ft_printf((current->st_mode & S_IWGRP) ? "w" : "-");
		print_long_alfa(base, current, w);
		current = current->next;
	}
}
