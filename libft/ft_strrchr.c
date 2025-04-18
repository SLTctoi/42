/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:33:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 12:33:28 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strrchr(const char *s, int c)
{
	char	*last_c;

	last_c = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_c = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last_c);
}
