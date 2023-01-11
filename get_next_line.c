/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:25:21 by lefreydier        #+#    #+#             */
/*   Updated: 2023/01/10 15:21:18 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buftmp)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buftmp);
	if (!tmp)
		return (NULL);
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
	buftmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buftmp)
		return (NULL);
	bytes_count = 1;
	while (bytes_count > 0)
	{
		bytes_count = read(fd, buftmp, BUFFER_SIZE);
		if (bytes_count == -1)
		{
			free(buftmp);
			return (NULL);
		}
		buffer[bytes_count] = 0;
		buffer = ft_free(buffer, buftmp);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buftmp, '\n'))
			break ;
	}
	free(buftmp);
	return (buffer);
}

char	*ft_line(char *buffer)
{

}

char	*ft_next(char *buffer)
{

}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buffer = ft_read(fd, buffer);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
