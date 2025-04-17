/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:28:23 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:29:25 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void    *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *ptr;
    
    i = 0;
    ptr = (unsigned char *)s;
    while (i < n)
    {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return (s);
}
