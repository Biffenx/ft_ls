/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:55:37 by jwilen            #+#    #+#             */
/*   Updated: 2020/09/07 06:01:58 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char			get_file_mode(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

char			file_acl(char path[PATH_MAX])
{
	acl_t	tmp;
	char	buf[101];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

static void		width_clmn_ext(t_data *current, int w[7], int len)
{
	w[1] = ft_max((int)ft_getintlen(current->st_nlink), w[1]);
	w[2] = ft_max((int)ft_strlen(current->st_uid_pwname), w[2]);
	w[3] = ft_max((int)ft_strlen(current->st_gid_grname), w[3]);
	if (!S_ISCHR(current->st_mode))
		len = (int)ft_getintlen(current->st_size);
	else
	{
		w[5] = ft_max((int)ft_getintlen(major(current->dev_t)), w[5]);
		w[6] = ft_max((int)ft_getintlen(minor(current->dev_t)), w[6]);
		len = w[5] + w[6] + 2;
	}
	w[4] = ft_max(len, w[4]);
}

int				width_clmn(t_data *current2, int w[7])
{
	int			len;
	int			blocks;
	t_data		*current;
	int			nbr;

	current = current2;
	w[5] = 3;
	w[6] = 3;
	len = 0;
	blocks = 0;
	while (current)
	{
		width_clmn_ext(current, w, len);
		nbr = current->st_blocks;
		w[0] = blocks += nbr;
		current = current->next;
	}
	w[5] = ft_max(w[4] - w[6] - 1, w[5]);
	return (1);
}
