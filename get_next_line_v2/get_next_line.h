#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char *ft_free_join(char *buffer,char *temp);
char *ft_first_line(int fd, char *buffer);
char *ft_get_line(char *buffer);
char *ft_clear_first_line(char *buffer);
char *get_next_line(int fd);

size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
