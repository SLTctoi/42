// ??? gerer le cas ./push_swap "1 2 3 4 5"





// marche que pour gerer le cas ./push_swap 1 2 3 4 5
// et gerer le cas ./push_swap 1 "2" 3 "4" 5 ???
void    parsing(char *nbr, t_list **lst_a)
{
    int n;
    t_list *node;

    n = ft_atoi(nbr);
    node = ft_lstnew(n);
    ft_lstadd_back(lst_a,node);
}
// return 1 si error et 0 si ok
// il faut verif si pas de doublon aussi !!!!!!!!!!!!
int verif(char **s)
{
    int i;
    int j;

    i = 1;
    while (s[i])
    {
        j = 0;
        if (s[i][j] == '+' || s[i][j] == '-')
            j++;
        while(s[i][j])
        {
            if (!ft_isdigit(s[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
// verif les doublons (pas oublier que +45 = 45)
int doublon(char **s)
{
    int i;
}