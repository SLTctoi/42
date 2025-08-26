#include "minishell.h"

/*
    IN: input = char **
    
    1 Order:
    echo "hello" > out.txt        # > après la commande
    cat < input.txt                # < après la commande
    echo "world" >> out.txt       # >> après la commande
    cat << EOF                     # << après la commande

    out: if extern command fork and exec command
         else if builtins command no fork just exec command with the good redirection
         else exec builtins and print
*/
/*
    < affecte aucun builtins
    > / >> affecte les builtins qui ecrivent sur stdout (echo, pwd, export, env)

    si grep "foo" < in1.txt < in2.txt utilise que in2.txt mais si il trouve pas in1 erreur pas de file in1.txt
    fqire une boucle 
*/

// 0 if ok and -1 if error
// use stdin_fileno
// trouver les bons codes erreur
int	redirection_stdin(char **input)
{
	int	i;
	int	fd;

	i = 1;
	while (input[i])
	{
		if (input[i][0] == '<' && ft_strlen(input[i]) == 1)
		{
			fd = open(input[i + 1], O_RDONLY);
			if (fd < 0)
			{
				perror("open");
				return (-1);
			}
			if (dup2(fd, STDIN_FILENO) < 0)
			{
				perror("dup2");
				close(fd);
				return (-1);
			}
			close(fd);
		}
		i++;
	}
	return (0);
}

int double_redirection_stdin(const char *delim)
{
    
}
