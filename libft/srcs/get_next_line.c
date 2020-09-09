/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:25:14 by jwilen            #+#    #+#             */
/*   Updated: 2020/06/10 15:58:37 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_next_line(char **s, char **line, const int fd)
{
	int				length;
	char			*temp;

	length = 0;
	while (s[fd][length] != '\n' && s[fd][length] != '\0')
		length++;
	if (s[fd][length] == '\n')
	{
		*line = ft_strsub(s[fd], 0, length);
		temp = ft_strdup(s[fd] + length + 1);
		free(s[fd]);
		s[fd] = temp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*s[FD_SIZE];
	char			buff[GNL_BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	if (fd < 0 || !line || fd > FD_SIZE)
		return (-1);
	while ((ret = read(fd, buff, GNL_BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(0);
		temp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = temp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	else
		return (ft_next_line(s, line, fd));
}
