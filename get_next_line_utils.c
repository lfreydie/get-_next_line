/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:55:59 by lefreydier        #+#    #+#             */
/*   Updated: 2023/01/18 15:20:00 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

// char	*ft_strdup(const char *s)
// {
// 	char	*res;
// 	int		len_s;
// 	int		i;

// 	i = 0;
// 	len_s = ft_strlen(s);
// 	res = malloc(sizeof(*res) * (len_s + 1));
// 	if (!res)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		res[i] = s[i];
// 		i++;
// 	}
// 	res[i] = 0;
// 	return (res);
// }

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*new;
// 	int		i;
// 	int		j;

// 	if (!s1 && !s2)
// 		return (free(s1), NULL);
// 	else if (!s1)
// 		new = ft_strdup(s2);
// 	else
// 	{
// 		new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 		if (!new)
// 			return (free(s1), NULL);
// 		j = 0;
// 		while (s1[j])
// 			new[i++] = s1[j++];
// 		j = 0;
// 		while (s2[j])
// 			new[i++] = s2[j++];
// 		new[i] = '\0';
// 	}
// 	return (free(s1), new);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_tot;
	char	*new;
	int		i;
	int		j;

	i = 0;
	len_tot = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc((len_tot + 1) * sizeof(char));
	if (!new || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (free(s1), new);
}
