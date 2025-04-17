/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:31:53 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:32:23 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *ud;
    const unsigned char *us;

    ud = (unsigned char *)dest;
    us = (const unsigned char *)src;
    i = 0;
    while (i < n)
    {
        ud[i] = us[i];
        i++;
    }
    return (dest);
}
