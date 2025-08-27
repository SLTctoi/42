#include "minishell.h"
//a faireSS
//int is_builtin(char *cmd);
//int run_builtin(char **argv);

static void free_pipes(int **pipes, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        if (pipes[i])
            free(pipes[i]);
    }
    free(pipes);
}

// cmd = [ [[cmd][arg]] [[cmd][arg]] ]
// n = size de cmd
// envp = env avec les vars
int	exec_pipe(char ***cmd, int n, char **envp)
{
	int	**pipes;
    pid_t pid;
    int i;
    int j;

    pipes = NULL;
    if (n < 1)
        return (-1);
    pipes = malloc(sizeof(int *) * (n - 1));
    if (!pipes)
        return (-1);
    i = 0;
    while (i < n - 1)
    {
        pipes[i] = malloc(sizeof(int) * 2);
        if (!pipes[i])
        {
            perror("malloc");
            free_pipes(pipes, i);
            return (-1);
        }
        if (pipe(pipes[i]) == -1)
        {
            perror("pipe");
            j = 0;
            free_pipes(pipes, i + 1);
            return (-1);
        }
        i++;
    }
    i = 0;
    while (i < n)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            j = 0;
            while (j < n - 1)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
                j++;
            }
            free_pipes(pipes, n - 1);
            return (-1);
        }
        if (pid == 0)
        {
            if (i == 0)
            {
                if (dup2(pipes[i][1], STDOUT_FILENO) == -1)
                {
                    perror("dup2");
                    exit(1);
                }
            }
            else if (i == n - 1)
            {
                if(dup2(pipes[i - 1][0], STDIN_FILENO) == -1)
                {
                    perror("dup2");
                    exit(1);
                }
            }
            else
            {
                if(dup2(pipes[i - 1][0], STDIN_FILENO) == -1)
                {
                    perror("dup2");
                    exit(1);
                }
                if(dup2(pipes[i][1], STDOUT_FILENO) == -1)
                {
                    perror("dup2");
                    exit(1);
                }
            }
            j = 0;
            while (j < n - 1)
            {
                close(pipes[j][0]);
                close(pipes[j][1]);
                j++;
            }
            if (is_builtin(cmd[i][0]))
            {
                run_builtin(cmd[i]);
                exit(0);
            }
            else
            {
                // check si acces a cmd[i][0]
                execve(cmd[i][0], cmd[i], envp); // remplacer cmd[i][0] par le path de la cmd
                perror("execve");
                exit (1);
            }

        }
        i++;
    }
    i = 0;
    while (i < n - 1)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
    free_pipes(pipes, n - 1);
    i = 0;
    while (i < n)
        wait(NULL); // utiliser waitpid pour les codes
    return(0);
}

// int		minipipe(t_mini *mini)
// {
// 	pid_t	pid;
// 	int		pipefd[2];

// 	pipe(pipefd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		ft_close(pipefd[1]);
// 		dup2(pipefd[0], STDIN);
// 		mini->pipin = pipefd[0];
// 		mini->pid = -1;
// 		mini->parent = 0;
// 		mini->no_exec = 0;
// 		return (2);
// 	}
// 	else
// 	{
// 		ft_close(pipefd[0]);
// 		dup2(pipefd[1], STDOUT);
// 		mini->pipout = pipefd[1];
// 		mini->pid = pid;
// 		mini->last = 0;
// 		return (1);
// 	}
// }
