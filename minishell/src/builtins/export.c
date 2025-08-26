#include "minishell.h"

// si 0 == ok si 1 == error
// int export(char *str, t_shell *shell)
// {
//     int i;

//     i = 0;
//     while (str[i] && ft_iswhitespace(str[i]))
//         i++;
//     i += 6;
//     while (str[i] && ft_iswhitespace(str[i]))
//         i++;
//     if (str[i] == '\0')
//     {
//         export_no_arg_no_opt(shell);
//         return (0);
//     }
//     else
//     {

//     }
//     return (1);
// }

int export(char *str, t_shell *shell)
{
    char **args;
    int ret;
    int first_error;
    int i;

    while (*str && *str == ' ')
        str++;
    args = ft_split_quote(str, " ");
    printf("split ok");
    if (!args[1])
    {
        export_no_arg_no_opt(shell);
        free_string_array(args);
        return(0);
    }
    first_error = 1;
    i = 1;
    while (args[i])
    {
        if (!is_valid_identifier(args[i]))
        {
            if (!first_error)
            {
                write(2, "minishell: export: `", 20);
                write(2, args[i], ft_strlen(args[i]));
                write(2, "': not a valid identifier\n", 27);
                first_error = 1;
            }
        }
        else
            add_or_update_env(shell, args[i]);
        i++;
    }
    free_string_array(args);
    if (first_error)
        ret = 1;
    else
        ret = 0;
    return (ret);
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
void export_arg(t_shell *shell, char **args)
{
    int i;
    int first_error;

    i = 1;
    first_error = 0;
    while (args[i])
    {
        if (args[i] && !is_valid_identifier(args[i]))
        {
            if (!first_error)
            {
                printf("minishell: export: `%s': not a valid identifier\n",
                       args[i]);
                first_error = 1;
            }
        }
        else
            add_or_update_env(shell, args[i]);
        i++;
    }
}
int is_valid_identifier(char *s)
{
    int i;

    if (!s || (!ft_isalpha(s[0]) && s[0] != '_'))
        return (0);
    i = 1;
    while (s[i] && s[i] != '=')
    {
        if (!ft_isalnum(s[i]) && s[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

void add_or_update_env(t_shell *shell, char *str)
{
    char *equal_sign;

    equal_sign = ft_strchr(str, '=');
    if (equal_sign) // VAR=val
    {
        replace_or_add(&shell->env, str);
    }
    else // VAR
    {
        if (!is_in_str_array(shell->var, str))
            shell->var = add_to_str_array(shell->var, str);
    }
}