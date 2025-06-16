void    rotate(t_list **lst)
{
    t_lst *first;
    t_lst *last;

    if (!lst || !*lst || !(*lst)->next)
        return ;
    first = *lst;
    last = *lst;
    while (last->next)
        last = last->next;
    *lst = (*lst)->next;
    last->next = first;
    first->next = NULL;
}

void    rotate_a(t_lst **lst_a)
{
    rotate(lst_a);
    write(1,"ra\n",3);
}

void    rotate_b(t_lst **lst_b)
{
    rotate(lst_b);
    write(1,"rb\n",3);
}

void    rotate_a_and_b(t_lst **lst_a, t_lst **lst_b)
{
    rotate(lst_b);
    rotate(lst_a);
    write(1,"rr\n",3);
}