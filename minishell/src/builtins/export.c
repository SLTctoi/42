#include "minishell.h"

// si 0 == ok si 1 == error
int export(char *str, t_shell *shell)
{
    int i;

    i = 0;
    while (str[i] && ft_iswhitespace(str[i]))
        i++;
    i += 6;
    while (str[i] && ft_iswhitespace(str[i]))
        i++;
    if (str[i] == '\0')
    {
        export_no_arg_no_opt(shell);
        return (0);
    }
    else
    {

    }
    return (1);
}

void export_no_arg_no_opt(t_shell *shell)
{
    char **sort_env;
    char **sort_var;
    int i;

    sort_env = copy_str_array_without_last(shell->env);
    sort_var = copy_string_array(shell->var);
    sort_lst(sort_env);
    sort_lst(sort_var);
    i = -1;
    while (sort_env[++i])
        printf("%s\n", sort_env[i]);
    i = -1;
    while (sort_var[++i])
        printf("%s\n", sort_var[i]);
    free_string_array(sort_env);
    free_string_array(sort_var);
}
// si je fais plusieurs export sur une meme commande mais que plusieurs export sont mauvais
// on ecris que pour le premier le msg d'erreur
void export_arg(t_shell *shell)
{
    // boucle en mode je verif si la var est bonne 
    // je stock la var 
    // je passe les space
    
}
// faire une fonction qui rajoute une var dans env

// faire une boucle pour gerer le cas de plusieurs var (ex : export var1=ok var2test)
// changer la val dans char **env
// les noms de var valide :
// doit commencer par une lettre ou _
// ne peut pas contenir de (-,!,@,*,.,...)

// export sans arugment
// 1. trier env et le mettre dans export->sort_env
//    sauf la derniere ligne qu on ecrit pas
//    et XMODIFIERS='@im=ibus' -> mettre les '
// 2. trier var et le mettre dans export->sort_var
// 3. ecrire les export