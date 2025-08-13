#include "minishell.h"

void parse_command(char *input, t_shell *shell)
{
    (void)shell; // car on l'utilise pas pour l'instant
    if (strncmp(input, "exit", 4) == 0 && (input[4] == '\0' || input[4] == ' '))
    {
        exit(0);
    }
}