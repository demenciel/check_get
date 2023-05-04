/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:07:46 by acouture          #+#    #+#             */
/*   Updated: 2023/05/04 13:47:22 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_saved(char *saved, int fd)
{
    int read_bytes;
    char *buffer;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    read_bytes = 1;
    while (!ft_strchr(saved, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(buffer);
            free(saved);
            return (NULL);
        }
        buffer[read_bytes] = '\0';
        saved = ft_strjoin(saved, buffer);
    }
    free(buffer);
    return (saved);
}

char *get_line_out(char *saved)
{
    char *line;
    int i = 0;
    
    if (!saved[i])
        return (NULL);
    while (saved[i] && saved[i] != '\n')
        i++;
    if (saved[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (saved[i] && saved[i] != '\n')
    {
        line[i] = saved[i];
        i++;
    }
    if (saved[i] && saved[i] == '\n')
    {
        line[i] = saved[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char *read_new_saved(char *saved)
{
    char *new;
    int i = 0;
    int j = 0;

    while (saved[i] && saved[i] != '\n')
        i++;
    if (!saved[i])
    {
        free(saved);
        return (NULL);
    }
    new = malloc((ft_strlen(saved) - i) + 1);
    if (!new)
        return (NULL);
    i++;
    while (saved [i] && saved[i])
        new[j++] = saved[i++];
    new[j] = '\0';
    free(saved);
    return (new);
}

char *get_next_line(int fd)
{
    static char *saved;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    saved = read_saved(saved, fd);
    if (!saved)
        return (NULL);
    line = get_line_out(saved);
    saved = read_new_saved(saved);
    return (line);
}

// int main()
// {
//     int fd = open("README.md", O_RDONLY);
//     while(printf("%s", get_next_line(fd)));
// }