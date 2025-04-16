/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:39:24 by mchrispe          #+#    #+#             */
/*   Updated: 2025/04/16 13:39:42 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// !! -2147483648
int ft_atoi(const char *nptr)
{
    int i;
    int nb;
    int sign;

    sign = 1;
    nb = 0;
    i = 0;
    while (nptr[i] == 32 || (nptr[i] >= 9 && nptr <= 13))
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            sign *= -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        nb *= 10 + (nptr[i] - '0');
        i++;
    }
    return (sign + result);
}