#include "minishell.h"

int get_output_file(char **cmd, int *fd_file)
{
    *fd_file = -1;
    if (!cmd || !cmd[0])
        return (0);
    if (ft_strcmp(cmd[0], ">") == 0)
    {
        if (cmd[1])
            *fd_file = open(cmd[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        return (1);
    }
    if (ft_strcmp(cmd[0], ">>") == 0)
    {
        if (cmd[1])
            *fd_file = open(cmd[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
        return (1);
    }
    return (0);
}
int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}
void	run_builtin(char **cmd)
{
	if (!cmd || !cmd[0])
		return ;
	if (ft_strcmp(cmd[0], "echo") == 0)
		builtin_echo(cmd);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		builtin_cd(cmd);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		builtin_pwd();
	else if (ft_strcmp(cmd[0], "export") == 0)
		builtin_export(cmd);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		builtin_unset(cmd);
	else if (ft_strcmp(cmd[0], "env") == 0)
		builtin_env();
	else if (ft_strcmp(cmd[0], "exit") == 0)
		builtin_exit();
}
