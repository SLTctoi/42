void    free_list(t_list *lst)
{
    t_list *temp;

    if (!lst)
        return ;
    while (lst)
    {
        temp = lst->next;
        if (lst->content)
            free(lst->content);
        if (lst->index)
            free(lst->content);
        free(lst);
        lst = temp;
    }
}

void    free_split(char **tab)
{
    int i;

    if (!tab)
        return ;
    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}