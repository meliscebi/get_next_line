/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melis <melis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:05:24 by melis             #+#    #+#             */
/*   Updated: 2025/08/14 04:10:11 by melis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_get_back(char *str)
{
    char *res;
	int i;
	
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
    return res;
}


static char	*ft_line(char *str)
{
    char *res;
	int i;
	int j;

    if (!str || !*str)
        return NULL;
	i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    res = malloc(i + 1);
    if (!res)
        return NULL;
    j = 0;
    while (j < i)
    {
        res[j] = str[j];
        j++;
    }
    res[i] = '\0';
    return (res);
}


static char	*ft_read_line(int fd, char *str, int read_bytes)
{
	char	*string;
	
	string = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while ((!ft_strchr(str, '\n')) && read_bytes != 0)
    {
        read_bytes = read(fd, string, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(string);
            return (NULL);
        }
        string[read_bytes] = '\0';
        str = ft_strjoin(str, string);
        if (!str)
        {
            free(string);
            return (NULL);
        }
    }
	free(string);
    return (str);
}


char	*get_next_line(int fd)
{
	char static	*str;
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