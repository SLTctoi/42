void    swap(t_list **lst)
{
    t_list *first;
    t_list *second;
    int temp;

    if (!lst || !*lst || !(*lst)->next)
        return ;
    first = *lst;
    second = (*lst)->next;

    temp = first->content;
    first->content = second->content;
    second->content = temp;
}

void    swap_a(t_lst **lst_a)
{
    swap(lst_a);
    write(1,"sa\n",3);
}

void    swap_b(t_lst **lst_b)
{
    swap(lst_b);
    write(1,"sb\n",3);
}

void    swap_a_and_b(t_lst **lst_a, t_lst **lst_b)
{
    swap(lst_a);
    swap(lst_b);
    write(1,"ss\n",3);
}