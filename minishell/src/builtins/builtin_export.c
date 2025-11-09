#include "minishell.h"

// permet d'afficher une var d'env au format d'export
static void	print_export_format_var(char *var)
{
	char *x;

	if (ft_strcmp(var, "_=./minishell") == 0)
		return ;
	ft_putstr_fd("declare -x ", 1);
	x = ft_strchr(var, '=');
	if (x)
	{
		write(1, var, x - var);
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(x + 1, 1);
		ft_putendl_fd("\"", 1);
	}
	else
		ft_putendl_fd(var, 1);
}

// verifie si la var est valide si oui l'ajoute dans env
static int	process_var(char *arg, t_pipe *p)
{
	char	*x;
	char	*clean;

	x = ft_strchr(arg, '=');
	if (x)
		*x = '\0';
	if (!is_valid_var(arg))
	{
		write(2, "export: '", 9);
		write(2, arg, ft_strlen(arg));
		write(2, "': not a valid identifier\n", 26);
		if (x)
			*x = '=';
		return (1);
	}
	if (x)
	{
		clean = strip_wrapping_quotes(x + 1);
		update_var_env(&p->envp, arg, clean);
		free(clean);
		*x = '=';
	}
	else
		update_var_env(&p->envp, arg, NULL);
	return (0);
}

// reproduit la commande export
int	builtin_export(char **args, t_pipe *p)
{
	int		i;
	int		err;
	char	**env;

	if (!args[1])
	{
		env = sorted_env(p->envp);
		i = 0;
		while (env[i])
			print_export_format_var(env[i++]);
		free_split(env);
		p->last_exit = 0;
		return (0);
	}
	i = 1;
	err = 0;
	while (args[i])
	{
		if (process_var(args[i], p))
			err = 1;
		i++;
	}
	p->last_exit = err;
	return (err);
}

