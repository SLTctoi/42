#include "minishell.h"

int	g_signal;

int	main(int ac, char **av, char **envp)
{
	t_pipe	p;

	(void)ac;
	(void)av;
	if (!init_minishell(&p, envp))
		return (1);
	while (handle_input(&p))
		;
	rl_clear_history();
	free_split(p.envp);
	return (0);
}
