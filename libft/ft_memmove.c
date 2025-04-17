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
    unsigned char *ud;
    unsigned char *us;

    ud = (unsigned char *)dest;
    us = (unsigned char *)src;
    if (us < ud && ud < us + n)
    {
        while (n--)
            ud[n] = us[n];
    }
    else
    {
        while (n--)
            *ud++ = *us++;
    }
    return (dest);
}