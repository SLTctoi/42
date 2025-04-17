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
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char dest1[50] = "Hello, World!";
    char dest2[50] = "Hello, World!";
    char src[] = "42 Cursus";

    printf("Custom: %s | Standard: %s\n", (char *)ft_memmove(dest1 + 6, src, 9), (char *)memmove(dest2 + 6, src, 9));

    char overlap1[50] = "Overlap Test";
    char overlap2[50] = "Overlap Test";

    printf("Custom: %s | Standard: %s\n", (char *)ft_memmove(overlap1 + 3, overlap1, 7), (char *)memmove(overlap2 + 3, overlap2, 7));

    char reverse1[50] = "Reverse Copy";
    char reverse2[50] = "Reverse Copy";

    printf("Custom: %s | Standard: %s\n", (char *)ft_memmove(reverse1, reverse1 + 3, 7), (char *)memmove(reverse2, reverse2 + 3, 7));

    return 0;
}
*/