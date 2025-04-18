/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:06:35 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/18 12:13:40 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		result = malloc(sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
		result[i++] = s[start + i];
	result[i] = '\0';
	return (result);
}
