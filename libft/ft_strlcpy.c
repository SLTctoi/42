/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:34:11 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:34:31 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  i;

    if(!src || !dst)
        return (0);
    i = 0;
    if (size > 0)
    {
        while (src[i] && i < size - 1)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (ft_strlen(src));
}
