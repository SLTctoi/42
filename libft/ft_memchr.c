/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:54:25 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 12:54:49 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *memchr(const void *s, int c, size_t n)
{
    unsigned char *ptr;
    unsigned char uc;
    size_t i;

    ptr = (unsigned char *)s;
    uc = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        if (ptr[i] == uc)
            return (ptr + i);
        i++;
    }
    return (NULL);
}