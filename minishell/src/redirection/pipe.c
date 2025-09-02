#include "minishell.h"

//a faireSS
//int is_builtin(char *cmd);
//int run_builtin(char **argv);

static void	free_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pipes[i])
			free(pipes[i]);
		i++;
	}
	free(pipes);
}

static void	close_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pipes[i])
		{
			close(pipes[i][0]);
			close(pipes[i][1]);
		}
		i++;
	}
}
static int	create_pipes(int ***pipes, int n)
{
	int	i;

	*pipes = malloc(sizeof(int *) * (n - 1));
	if (!*pipes)
		return (-1);
	i = 0;
	while (i < n - 1)
	{
		(*pipes)[i] = malloc(sizeof(int) * 2);
		if (!(*pipes)[i])
			return (perror("malloc"), free_pipes(*pipes, i), -1);
		if (pipe((*pipes)[i]) == -1)
			return (perror("pipe"), free_pipes(*pipes, i + 1), -1);
		i++;
	}
	return (0);
}
static void setup_redirections(char **cmd, int **pipes, int i, int n)
{
    int fd_file;
    int has_output;

    fd_file = -1;
    has_output = get_output_file(cmd, &fd_file);
    if (i > 0)
        dup2(pipes[i - 1][0], STDIN_FILENO);
    if (i < n - 1)
        dup2(pipes[i][1], STDOUT_FILENO);
    if (has_output && fd_file != -1)
    {
        dup2(fd_file, STDOUT_FILENO);
        close(fd_file);
    }
    redirection_loop(cmd);
}
static void child_exec(t_child child)
{
    int j;

    setup_redirections(child.cmd, child.pipes, child.index, child.total);
    j = 0;
    while (j < child.total - 1)
    {
        close(child.pipes[j][0]);
        close(child.pipes[j][1]);
        j++;
    }
    if (is_builtin(child.cmd[0]))
    {
        run_builtin(child.cmd);
        exit(0);
    }
    execve(child.cmd[0], child.cmd, child.envp);
    perror("execve");
    exit(127);
}
static int exec_pipe_init (int ***pipes, int n)
{
    if (create_pipes(pipes, n) == -1)
        return (-1);
    return (0);
}

static int exec_pipe_fork(char ***cmd, int **pipes, int n, char **envp)
{
    int i;
    pid_t pid;
    t_child child;

    i = 0;
    while (i < n)
    {
        pid = fork();
        if (pid == -1)
            return (perror("fork"), close_pipes(pipes, n - 1),
                    free_pipes(pipes, n - 1), -1);
        if (pid == 0)
        {
            child.cmd = cmd[i];
            child.pipes = pipes;
            child.index = i;
            child.total = n;
            child.envp = envp;
            child_exec(child);
        }
        i++;
    }
    return (0);
}
static void exec_pipe_wait(int **pipes, int n)
{
    int i;

    close_pipes(pipes, n - 1);
    free_pipes(pipes, n - 1);
    i = -1;
    while (++i < n)
        wait(NULL);
}
int exec_pipe(char ***cmd, int n, char **envp)
{
    int **pipes;
    
    if (n < 1)
        return (-1);
    if (exec_pipe_init(&pipes, n) == -1)
        return (-1);
    if (exec_pipe_fork(cmd, pipes, n, envp) == -1)
        return (-1);
    exec_pipe_wait(pipes, n);
    return (0);
}