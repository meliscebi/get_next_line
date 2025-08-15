/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melis <melis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:05:24 by melis             #+#    #+#             */
/*   Updated: 2025/08/14 17:03:05 by melis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_back(char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	res = ft_substr(str, i, ft_strlen(str + i));
	free(str);
	return (res);
}

static char	*ft_line(char *str)
{
	int i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (ft_substr(str, 0, i));
}

static char	*ft_free_and_join(char *str, char *string)
{
	char	*temp;

	temp = ft_strjoin(str, string);
	free(str);
	return (temp);
}

static char	*ft_read_line(int fd, char *str, int read_bytes)
{
	char	*string;

	string = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!string)
		return (free(str), NULL);
	while ((!ft_strchr(str, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, string, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(string);
			free(str);
			return (NULL);
		}
		string[read_bytes] = '\0';
		str = ft_free_and_join(str, string);
		if (!str)
			return(free(string), NULL);
	}
	free(string);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 1;
	str = ft_read_line(fd, str, read_bytes);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_get_back(str);
	return (line);
}