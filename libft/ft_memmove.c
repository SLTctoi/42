/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:52:54 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:53:15 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// si chevauchement on copie de la fin vers le debut sinon debut vers la fin
void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (s < d && d < s + n)
    {
        while (n--)
            d[n] = s[n]
    }
    else
    {
        while (n--)
            *d++ = *s++;
    }
    return (dest);
}