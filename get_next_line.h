/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:55:01 by lefreydier        #+#    #+#             */
/*   Updated: 2023/01/18 16:31:13 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*ft_read(int fd, char *buffer);
char	*ft_tmp(char *tmp, char *buffer);
int		ft_strchr(char *str, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
