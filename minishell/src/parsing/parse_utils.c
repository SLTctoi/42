#include "minishell.h"

// vérifie qu'il n'y a pas de | après une redirection (pas de >|)
int	check_pipe_after_redir(char ***cmds, int i, int j, t_pipe *p)
{
	if (cmds[i][j + 1] && cmds[i][j + 1][0] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	if (cmds[i][j][1] == '|' || (cmds[i][j][1] == '>' && cmds[i][j][2] == '|'))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		p->last_exit = 2;
		return (0);
	}
	return (1);
}
