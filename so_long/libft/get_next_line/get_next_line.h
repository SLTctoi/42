/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:33:54 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/14 15:18:28 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_free_join(char *buffer, char *temp);
char	*ft_first_line(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_clear_first_line(char *buffer);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

char	*create_remaining_buffer(char *buffer, int i);

#endif
