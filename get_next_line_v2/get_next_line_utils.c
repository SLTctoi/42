/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:22:55 by mchrispe          #+#    #+#             */
/*   Updated: 2025/05/15 10:23:10 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    size_t	i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == 0)
        return ((char *)s);
    return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
    size_t	len1 = ft_strlen(s1);
    size_t	len2 = ft_strlen(s2);
    char	*buf = malloc(len1 + len2 + 1);
    size_t	i = 0, j = 0;

    if (!buf)
        return (NULL);
    while (i < len1)
    {
        buf[i] = s1[i];
        i++;
    }
    while (j < len2)
        buf[i++] = s2[j++];
    buf[i] = 0;
    free(s1);
    return (buf);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
    size_t	i = 0;
    size_t	slen = ft_strlen(s);
    char	*buf;

    if (!s || start >= slen)
        return (NULL);
    if (len > slen - start)
        len = slen - start;
    buf = malloc(len + 1);
    if (!buf)
        return (NULL);
    while (i < len)
    {
        buf[i] = s[start + i];
        i++;
    }
    buf[i] = 0;
    return (buf);
}
