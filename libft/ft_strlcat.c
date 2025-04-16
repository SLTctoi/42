/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:14:14 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 11:14:45 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t  ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t dest_len;
    size_t src_len;

    i = 0;
    j = 0;
    dest_len = ft_strlen(dest);
    src_len = ft_strlen(src);
    if (size <= dest_len)
        return (size + src_len);
    i = dest_len;
    while (src[j] && i < size - 1)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest_len + src_len);
}