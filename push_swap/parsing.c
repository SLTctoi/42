void    parsing(int ac, char **av, t_lst **lst_a)
{
    int i;
    int j;
    t_list *node;
    char **s;

    i = 1;
    while (i < ac - 1)
    {
        s = ft_split(av[i],"    ");// refaire le split pour qu il marche avec plusieurs char
        j = 0;
        while (s[j])
        {
            ft_lstadd_back(lst_a, lstnew(ft_atoi(s[j])));
            j++;
        }
        i++;
    }
}
// return 1 si error et 0 si ok
int verif(char **s)
{
    int i;
    int j;
    int nl;

    i = 1;
    nl = 1;
    while (s[i])
    {
        if (nl)
        {
            j = 0;
            nl = 0;
        }
        if (s[i][j] == ' ' || s[i][j] == '  ')
            j++;
        if (s[i][j] == '+' || s[i][j] == '-')
            j++;
        while(s[i][j] || s[i][j] != ' ' || s[i][j] != ' ')
        {
            if (!ft_isdigit(s[i][j]))
                return (1);
            j++;
        }
        if (s[i][j] == '\0')
        {
            i++;
            nl = 1;
        }
    }
    return (0);
}
// verif apres le atoi car y a plus les +
//return 1 si doublon et 0 si pas doublon
int doublon(t_list *lst)
{
    t_list *current;
    t_list *check;

    current = lst;
    while (current)
    {
        check = current->next;
        while (check)
        {
            if (*(int *)current->content == *(int *)check->content)
                return (1);
            check = check->next;
        }
        current = current->next;
    }
    return (0);
}

// check si c est deja trié
// check si dans list_a cest decroissant car je rajoute a la fin dabord
// return 1 si deja trie et 0 si pas encore  
int already_sort(t_list *lst)
{
    t_list *current;
    t_list *nxt;

    current = lst;
    if (!lst)
        return (1);
    while (current)
    {
        nxt = current->next;
        while (nxt)
        {
            if (*(int *)current->content <= *(int *)nxt->content)
                return (0);
            nxt = nxt->next;
        }
        current = current->next;
    }
    return (1);
}
