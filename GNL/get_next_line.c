/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoares <msoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:31:41 by msoares           #+#    #+#             */
/*   Updated: 2020/03/02 19:40:55 by msoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

static int		get_line(int fd, char **heap, char **line)
{
	int			i;
	char		*tmp;

	i = 0;
	if (fd < 0)
		return (-1);
	else if (fd == 0 && heap[0] == '\0')
	{
		*line = ft_strdup("");
		ft_strdel(heap);
		return (0);
	}
	while ((*heap)[i] != '\n' && (*heap)[i] != '\0')
		i++;
	*line = ft_substr(*heap, 0, i);
	if ((*heap)[i] == '\n')
	{
		tmp = ft_strdup(*heap + i + 1);
		free(*heap);
		*heap = tmp;
		return (1);
	}
	ft_strdel(heap);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			bytes;
	char		*buf;
	static char	*reminder[OPEN_MAX];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(reminder[fd]))
	{
		if (!(reminder[fd] = ft_strdup("")))
			return (-1);
	}
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(*buf))))
		return (-1);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		tmp = ft_strjoin(reminder[fd], buf);
		ft_strdel(&reminder[fd]);
		reminder[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (get_line(bytes, &reminder[fd], line));
}
