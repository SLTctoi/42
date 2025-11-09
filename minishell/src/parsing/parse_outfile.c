#include "minishell.h"

// stock le nom du fichier et si c'est en append
int	set_outfile(t_cmd *cmd, char *token)
{
	if (token[1] == '>')
	{
		cmd->outfile = ft_strdup(token + 2);
		cmd->append = 1;
	}
	else
		cmd->outfile = ft_strdup(token + 1);
	return (1);
}

// gère les erreurs de outfile
int	outfile_error(int nb_cmds, int *redir_error)
{
	*redir_error = 1;
	if (nb_cmds == 1)
		return (0);
	return (1);
}
// gère les cas (> fichier et >> fichier)
static int	separate_outfile(char ***cmds, t_cmd *cmd,
		int *j, t_out_params prm)
{
	if (!check_pipe_after_redir(cmds, prm.prm.i, *j, prm.prm.p))
		return (0);
	return (handle_outfile_redirect(cmds, cmd, j, prm));
}

// gere les redirections outfile et les cas spécifiques
int	outfile_redir(char ***cmds, t_cmd *cmd, int *j, t_out_params prm)
{
	if (ft_strcmp(cmds[prm.prm.i][*j], ">") == 0
		|| ft_strcmp(cmds[prm.prm.i][*j], ">>") == 0)
	{
		prm.append = (ft_strcmp(cmds[prm.prm.i][*j], ">>") == 0);
		return (separate_outfile(cmds, cmd, j, prm));
	}
	else if (cmds[prm.prm.i][*j][0] == '>')
		return (attached_outfile(cmds, cmd, j, prm));
	return (1);
}
