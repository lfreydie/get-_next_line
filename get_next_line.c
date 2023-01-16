/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:25:21 by lefreydier        #+#    #+#             */
/*   Updated: 2023/01/16 15:54:34 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buftmp)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buftmp);
	if (!tmp)
		return (free(buffer), free(buftmp), NULL);
	free (buffer);
	return (tmp);
}

char	*ft_read(int fd, char *buffer)
{
	char	*buftmp;
	int		bytes_count;

	if (!buffer)
	{
		buffer = (char *)ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	buftmp = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buftmp)
		return (free(buffer), NULL);
	bytes_count = 1;
	while (bytes_count > 0)
	{
		bytes_count = read(fd, buftmp, BUFFER_SIZE);
		if (bytes_count == -1)
			return (free(buffer), free(buftmp), NULL);
		buffer = ft_free(buffer, buftmp);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buftmp, '\n') || ft_strchr(buftmp, '\0'))
			break ;
	}
	free(buftmp);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	char	*res;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i ++;
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		res[i] = buffer[i];
		i ++;
	}
	if (buffer[i] && buffer[i] == '\n')
		res[i++] = '\0';
	return (res);
}

char	*ft_next(char *buffer)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	res = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i++;
	while (buffer[i])
		res[j++] = buffer[i++];
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) || fd > 1024)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
		return (free(buffer), NULL);
	if(!line[0])
		return (NULL);
	buffer = ft_next(buffer);
	if (!buffer)
		return (free(buffer), free(line), NULL);
	return (line);
}
