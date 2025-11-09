#include "minishell.h"

// reproduit la commande pwd
int	builtin_pwd(t_pipe *p, char **args)
{
	char	cwd[4096];

	(void)args;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_putendl_fd(cwd, 1);
		p->last_exit = 0;
		return (0);
	}
	perror("pwd");
	p->last_exit = 1;
	return (1);
}
