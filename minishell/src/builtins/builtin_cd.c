#include "minishell.h"

// change le répertoire courant et met à jour PWD et OLDPWD
static int change_directory(t_pipe *p, char *path)
{
    char *oldpwd;
    char *newpwd;

    oldpwd = getcwd(NULL, 0);
    if (!path)
    {
        int idx = index_env(p->envp, "HOME");
        if (idx >= 0)
            path = ft_strchr(p->envp[idx], '=') + 1;
    }
    if (!path)
        return (write(2, "cd: HOME or OLDPWD not set\n", 27), free(oldpwd), 1);
    if (chdir(path) != 0)
        return (perror("cd"), free(oldpwd), 1);
    newpwd = getcwd(NULL, 0);
    update_var_env(&p->envp, "OLDPWD", oldpwd);
    update_var_env(&p->envp, "PWD", newpwd);
    free(oldpwd);
    free(newpwd);
    return (0);
}


// Détermine le chemin pour la commande cd. Gère les cas spéciaux (vide , - et --)
// cd vide -> HOME | cd -- -ok (pour aller dans un dossier qui comence par -) | cd - -> OLDPWD
static char *get_cd_path(char **args, t_pipe *p)
{
    int idx;

    if (!args[1])
        return (NULL);
    if (ft_strcmp(args[1], "--") == 0)
    {
        if (args[2])
            return (args[2]);
        return (NULL);
    }
    if (ft_strcmp(args[1], "-") == 0)
    {
        idx = index_env(p->envp, "OLDPWD");
        if (idx >= 0)
            return (ft_strchr(p->envp[idx], '=') + 1);
        return (NULL);
    }
    return (args[1]);
}


// Gère le cas "cd -" -> change de répertoire pour aller dans OLDPWD
static int cd_minus(t_pipe *p)
{
    char *path;
    int idx;

    idx = index_env(p->envp, "OLDPWD");
    if (idx >= 0)
        path = ft_strchr(p->envp[idx], '=') + 1;
    else
        path = NULL;
    if (!path)
        return (write(2, "cd: OLDPWD not set\n", 19), 1);
    if (change_directory(p, path) == 0)
    {
        idx = index_env(p->envp, "PWD");
        if (idx >= 0)
        {
            path = ft_strchr(p->envp[idx], '=') + 1;
            write(1, path, ft_strlen(path));
            write(1, "\n", 1);
        }
    }
    return (0);
}

// reproduit la commande cd
int builtin_cd(char **args, t_pipe *p)
{
    char *path;

    if (args[1] && args[2])
    {
        write(2, " too many arguments\n", 20);
        return (1);
    }
    if (args[1] && ft_strcmp(args[1], "-") == 0)
        return (cd_minus(p));
    path = get_cd_path(args, p);
    return (change_directory(p, path));
}

