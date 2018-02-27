/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:55:23 by ikozlov           #+#    #+#             */
/*   Updated: 2018/02/26 21:53:44 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_new_line(char	*line)
{
	int		i;

	i = -1;
	while (line && line[++i])
		if (line[i] == '\n')
			return (i);
	return (-1);
}

static int	read_file(const int fd, char **buffers)
{
	char	*buff;
	char	*tmp;
	int		cursor;
	int		buff_len;

	buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if ((cursor = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff_len = buffers[fd] ? ft_strlen(buffers[fd]) : 0;
		tmp = (char *)malloc(sizeof(char) * (buff_len + cursor + 1));
		buffers[fd] ? ft_strcat(tmp, buffers[fd]) : (void)0;
		ft_strcat(tmp, buff);
		buff[buff_len + cursor] = '\0';
		free(buffers[fd]);
		buffers[fd] = buff;
	}
	return (cursor);
}

static int	read_line(const int fd, char **buffers)
{
	int		nl;
	int		cursor;

	// nothing
	if (!buffers[fd] && ((cursor = read_file(fd, buffers)) <= 0))
			return (cursor);
	// less then a line
	while ((nl = has_new_line(buffers[fd])) < 0)
	{
		cursor = read_file(fd, buffers);
		if (cursor <= 0)
			return (cursor);
	}
	// more then a line
	// a line
	return (nl);
}

int			get_next_line(const int fd, char **line)
{
	static char **buffers;
	char		*tmp;
	int			buff_len;
	int			nl;

	// todo: check for max buff size?
	if (fd < 0 || !line || fd > FT_LIMIT || BUFF_SIZE < 1)
		return (EOF);
	if (!buffers)
		buffers = (char **)malloc(sizeof(char *) * FT_LIMIT);
	nl = read_line(fd, buffers);
	if (nl >= 0 && buffers[fd])
	{
		buff_len = ft_strlen(buffers[fd]);
		*line = (char *)malloc(sizeof(char) * (nl + 1));
		ft_strncpy(*line, buffers[fd], nl);
		(*line)[nl] = '\0'
		tmp = (char *)malloc(sizeof(char) * (buff_len - nl + 1));
		ft_strcpy(tmp, *(buffers + fd) + nl + 1);
		tmp[buff_len - nl] = '\0';
		free(buffers[fd]);
		buffers[fd] = tmp;
	}
	return (nl);
}