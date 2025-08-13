#include "minishell.h"

// void    ft_malloc(size_t size)
// {
//     void    *p;

//     if (size == 0)
//         return (NULL);
//     p = malloc(size);
//     if (!p)
//     {
//         perror(RED"Error: Malloc failed"RST);
//         exit(1); // trouver le bon code error !!!
//     }
//     return (p);
// }

// pid_t   ft_fork(void)
// {
//     pid_t pid;

//     pid = fork();
//     if (pid < 0)
//     {
//         perror(RED"Error: Fork failed"RST);
//         exit(1); // trouver le bon code error !!!
//     }
//     return (pid);
// }
