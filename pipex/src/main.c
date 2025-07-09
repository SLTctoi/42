/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:27:00 by mchrispe          #+#    #+#             */
/*   Updated: 2025/07/07 10:27:03 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_proc(char **av, char **env, int *fd)
{
	int	f;

	f = open(av[1], O_RDONLY, 0777);
	if (f == -1)
		error();
	dup2(f, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	execute(av[2], env);
}

void	parent_proc(char **av, char **env, int *fd)
{
	int	f;

	f = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (f == -1)
		error();
	dup2(f, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("Ex : ./pipex infile cmd1 cmd2 outfile\n", 1);
		return (0);
	}
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		child_proc(av, env, fd);
	waitpid(pid, NULL, 0);
	parent_proc(av, env, fd);
}
