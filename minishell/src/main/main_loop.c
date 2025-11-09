#include "minishell.h"

// check si input est vide
static int	is_empty_input(char *input)
{
	char	*tmp;

	tmp = input;
	while (*tmp && (*tmp == ' ' || *tmp == '\t' || *tmp == '\n'))
		tmp++;
	if (!*tmp)
		return (1);
	return (0);
}

//gère le cycle de l'input : parse, init cmds, execute, free
static void	process_input(char *input, t_pipe *p)
{
	char	***cmds;
	t_cmd	**cmds_meta;
	int		nb_cmds;
	int		i;

	cmds = parse_commands(input, &nb_cmds, p);
	if (!cmds)
		return ;
	cmds_meta = init_cmds(cmds, nb_cmds, p);
	if (!cmds_meta)
	{
		free_triple_pointer(cmds);
		return ;
	}
	execute_pipeline(cmds_meta, nb_cmds, p->envp, p);
	i = -1;
	while (++i < nb_cmds)
		free_cmd(cmds_meta[i]);
	free(cmds_meta);
	free_triple_pointer(cmds);
}

// boucle principale qui récupère l'input et le traite
int	handle_input(t_pipe *p)
{
	char	*input;

	g_signal = 0;
	input = readline("minishell> ");
	if (!input)
		return (0);
	if (*input)
		add_history(input);
	if (!is_empty_input(input))
		process_input(input, p);
	free(input);
	return (1);
}
