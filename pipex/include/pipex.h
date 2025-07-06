#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

// src/main.c
void    child_proc(char **av, char **env, int *fd);
void    parent_proc(char **av, char **env, int *fd);

// src/utils.c
char    *get_path(char *s, char **env);
char **get_all_paths(char **env);
void free_split(char **tab);
void execute(char *av, char **env);
void error(void);

// libft
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif