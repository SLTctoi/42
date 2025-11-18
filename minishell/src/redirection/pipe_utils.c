/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchrispe <mchrispe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:44:37 by mchrispe          #+#    #+#             */
/*   Updated: 2025/11/18 14:45:10 by mchrispe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_all_pipes(int **fd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	free_all_fd(int **fd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (fd[i])
			free(fd[i]);
		i++;
	}
	if (fd)
		free(fd);
}

// initialise chaque pipe
int	**init_pipes(int n)
{
	int	**fd;
	int	i;

	fd = malloc(sizeof(int *) * (n - 1));
	if (!fd)
		return (NULL);
	i = -1;
	while (++i < n - 1)
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (!fd[i] || pipe(fd[i]) == -1)
		{
			free_all_fd(fd, i);
			return (NULL);
		}
	}
	return (fd);
}

// init pour pipe.c
void	init_pipeline_ctx(t_pipe *p, int **fd, int n, char **envp)
{
	p->fd = fd;
	p->n = n;
	p->envp = envp;
}

void	clean_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i][0] != '\0')
			argv[j++] = argv[i];
		else
			free(argv[i]);
		i++;
	}
	argv[j] = NULL;
}
