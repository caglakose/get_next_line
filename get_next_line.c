/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakose <cakose@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:52:52 by cakose            #+#    #+#             */
/*   Updated: 2024/10/03 14:53:04 by cakose           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_buffer(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*next;

	i = 0;
	j = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer || !buffer[i])
		return (free(buffer), NULL);
	next = ft_calloc(ft_strlen(buffer) - i + 1);
	if (!next)
		return (NULL);
	i++;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = 0;
	free(buffer);
	return (next);
}

static char	*rd_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

static char	*rd_file(int fd, char *str)
{
	char	*tmp;
	char	*next_line;
	int		byte_read;

	if (!str)
		str = ft_calloc(1);
	tmp = ft_calloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(str, '\n'))
	{
		byte_read = read(fd, tmp, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(str), free(tmp), NULL);
		tmp[byte_read] = 0;
		next_line = ft_strjoin(str, tmp);
		free(str);
		str = next_line;
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer = 0;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = rd_file(fd, buffer);
	next_line = rd_line(buffer);
	buffer = clean_buffer(buffer);
	return (next_line);
}
