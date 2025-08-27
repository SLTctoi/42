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

// child write in the pipe | parent read in the pipe
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
        if (pid == 0) // enfant
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
                exit(0); // close child processus
            }
            else
            {
                // check si acces a cmd[i][0]
                execve(cmd[i][0], cmd[i], envp);
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
        wait(NULL);
    return(0);
}
