/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melis <melis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:05:03 by melis             #+#    #+#             */
/*   Updated: 2025/08/14 04:16:41 by melis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			result[i] = s1[i];
		else
			result[i] = s2[i - s1_len];
		i++;
	}	
	result[i] = '\0';
	return (result);
}

char *ft_substr(char *s, int start, int len)
{
    char *res;
    int i;

    if (!s)
        return NULL;
    if (start >= ft_strlen(s))
    {
        res = malloc(1);
        if (!res)
            return NULL;
        res[0] = '\0';
        return res;
    }
    if (ft_strlen(s + start) < len)
        len = ft_strlen(s + start);
    res = malloc(len + 1);
    if (!res)
        return NULL;
    i = 0;
    while (i < len)
    {
        res[i] = s[start + i];
        i++;
    }
    res[i] = '\0';
    return res;
}

