#include "minishell.h"

// verifie si cmd est un builtin
int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") ||
		!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "env") ||
		!ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, "export") ||
		!ft_strcmp(cmd, "unset"))
		return (1);
	return (0);
}

// exec un builtin en fonction du nom
int	exec_builtin(char **args, t_pipe *p)
{
	if (!args[0])
		return (1);
	if (!ft_strcmp(args[0], "echo"))
		return (builtin_echo(args, p));
	if (!ft_strcmp(args[0], "cd"))
		return (builtin_cd(args, p));
	if (!ft_strcmp(args[0], "pwd"))
		return (builtin_pwd(p, args));
	if (!ft_strcmp(args[0], "env"))
		return (builtin_env(args, p));
	if (!ft_strcmp(args[0], "exit"))
		return (builtin_exit(args, p));
	if (!ft_strcmp(args[0], "export"))
		return (builtin_export(args, p));
	if (!ft_strcmp(args[0], "unset"))
		return (builtin_unset(args, p));
	return (1);
}
