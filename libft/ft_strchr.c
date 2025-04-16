/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:20:06 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 12:20:29 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    if (c == '\0')
        return ((char *)s + ft_strlen(s))
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return ((char *)s + i);
        i++;
    }
    return (NULL);
}