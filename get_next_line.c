/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melis <melis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 03:47:11 by melis             #+#    #+#             */
/*   Updated: 2025/08/11 02:29:08 by melis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_str(char *str, char *string)
{
	char	*temp;

	temp = ft_strjoin(str, string);
	free(str);
	return (temp);
}

static char *ft_save(char *str)
{
    int i;
    int j;
    char *res;
    
    i = 0;
    j = 0;
    while(str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    i++;
    while (str[i + j])
        j++;
    res = malloc(sizeof(char) * (j + 1));
    if (!res)
        return (NULL);
    j = 0;
    while (str[i] != '\0')
        res[j++] = str[i++];
    res[j] = '\0';
    free(str);
    return (res);
}

static char *ft_line(char *str)
{
    int i;
    char *res;

    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    res = malloc(i + 2);
    if (!res)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        res[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        res[i] = '\n';
        i++;
    } 
    res[i] = '\0';
    return (res);
}

static char *ft_read(int fd, char *str)
{
    char    *string;
    int     read_bytes;
    
    string = malloc(BUFFER_SIZE + 1);
    if (!string)
        return (NULL);
    read_bytes = 1;
    while (!ft_strchr(str, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, string, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(string);
            return (NULL);
        }
        string[read_bytes] = '\0';
        str = ft_free_str(str, string);
        if (!str)
        {
            free(string);
            return (NULL);
        }
    }
    free(string);
    return (str);
}

char *get_next_line(int fd)
{
    static char *str;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_read(fd, str);
    if (!str)
        return (NULL);
    line = ft_line(str);
    str = ft_save(str);
    return (line);
}
