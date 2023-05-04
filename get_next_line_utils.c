/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:07:48 by acouture          #+#    #+#             */
/*   Updated: 2023/05/04 13:53:31 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strchr(char *str, char c)
{
    int i = 0;

    if (!str)
        return (NULL);
    while (str[i])
    {
        if (str[i] == c)
            return (str + i);
        i++;
    }
    if (str[i] == c)
        return (str + i);
    return (NULL);
}

char *ft_strjoin(char *saved, char *buffer)
{
    char *joined;
    int i = 0;

    if (!saved)
    {
        saved = malloc(1);
        saved[0] = '\0';
    }
    if (!saved || !buffer)
        return (NULL);
    joined = malloc((ft_strlen(saved) + ft_strlen(buffer)) + 1);
    if (!joined)
        return (NULL);
    for (int j = 0; saved[j]; j++) {
        joined[i++] = saved[j];
    }
    for (int j = 0; buffer[j]; j++) {
        joined[i++] = buffer[j];
    }
    joined[i] = '\0';
    free(saved);
    return (joined);
}