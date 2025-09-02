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
int redirection_loop(char **input)
{
    int i;
	
    i = 1;
    while (input[i] && input[i + 1])
    {
		if (redirection_stdin(input[i], input[i + 1]) == -1)
			return (-1);
		if (double_redirection_stdin(input[i], input[i + 1]) == -1)
			return (-1);
		if (redirection_stdout(input[i], input[i + 1]) == -1)
			return (-1);
		i++;
    }
    return 0;
}

int	redirection_stdin(char *input ,char *file)
{
	int	fd;
	
	if (ft_strcmp(input, "<") == 0)
	{
		fd = open(file, O_RDONLY);
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
	return (0);
}
// on readline -> on stock dans un fichier temp -> on stdin dans le fichier temp -> on unlink le fichier temp
int double_redirection_stdin(char *input, const char *delim)
{
	int pipefd[2];
	char *line;

    if (ft_strcmp(input, "<<") == 0)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			return (-1);
		}
		while (1)
		{
			line = readline("heredoc> ");
			if (!line)
				break;
			if (ft_strcmp(line, delim) == 0)
			{
				free(line);
				break;
			}
			write(pipefd[1], line, ft_strlen(line));
			write(pipefd[1], "\n", 1);
			free(line);
		}
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) < 0)
		{
			perror("dup2");
			close(pipefd[0]);
			return (-1);
		}
		close(pipefd[0]);
	}
	return (0);
}

int	redirection_stdout(char *input, char *file, int pipe_fd)
{
	int		fd;
	char	buf[1024];
	int		nbytes;

	if (!input || input[0] != '>')
		return (0);
	if (ft_strcmp(input, ">") == 0)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_strcmp(input, ">>") == 0)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (-1);
	if (fd < 0)
		return (perror("open"), -1);
	if (pipe_fd != -1)
	{
		while ((nbytes = read(pipe_fd, buf, sizeof(buf))) > 0)
			write(fd, buf, nbytes);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (perror("dup2"), close(fd), -1);
	close(fd);
	return (0);
}

