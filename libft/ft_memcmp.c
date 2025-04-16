/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:10:43 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 13:11:03 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
    size_t  i;

    i = 0;
    us1 = (unsigned char *)s1;
    us2 = (unsigned char *)s2;
    while (i < n)
    {
        if (us1[i] != us2[i])
            return ((unsigned char)us1[i] - (unsigned char)us2[i]);
        i++;
    }
    return (0);
}