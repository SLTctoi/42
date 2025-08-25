#include "minishell.h"

int main(int ac, char **av, char **env)
{
    t_shell shell;
    char *input;

    (void)ac;
    (void)av;
    shell.env = env; // make a copy env for modify the array
    if(!init_path(&shell))
        return (1);        
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

        // Exemple : simple parsing très basique
        if (strncmp(input, "export", 6) == 0 && (input[6] == '\0' || input[6] == ' '))
        {
            printf("ok 1\n");
            export(input + 6, &shell);           // args = "" si pas d'argument
        }
        else
        {
            printf("ok 2\n");
            parse_command(input, &shell); // le reste des commandes
        }
        free(input);
    }

    free_shell(&shell);
    return (0);
}