/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:44:02 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 10:44:17 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc de len de s ?


char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *result;
    size_t  i;

    if (!s || !f) 
        return (NULL);
    result = malloc(sizeof(char) * (ft_strlen(s) + 1)); 
    if (!result)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        result[i] = f(i, s[i]);
        i++;
    }
    result[i] = '\0';
    return (result);
}
