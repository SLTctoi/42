#include "minishell.h"

int main(int ac, char **av, char **env)
{
    t_shell shell;
    char *input;

    (void)ac;
    (void)av;
    shell.env = env;
    while (1)
    {
        input = readline("minishell> ");
        if (!input)
        {
            printf("exit\n");
            break;
        }
        if (*input)
            add_history(input);
        parse_command(input, &shell);
        free(input);
    }
    free_shell(&shell);
    return (0);
}