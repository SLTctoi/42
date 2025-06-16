void    push(t_list **lst_1, t_list **lst_2)
{
    t_list *node;

    if (!lst_1 || !*lst_1)
        return ;
    node = ft_lstnew((*lst_1)->content);
    ft_lstadd_front(lst_2, node);
    t_list *temp = *lst_1;
    *lst_1 = (*lst1)->next;
    free(temp)
}

void    push_a(t_list **lst_a, t_list **lst_b)
{
    push(lst_a, lst_b);
    write(1,"pa\n",3);
}

void    push_b(t_list **lst_b, t_list **lst_a)
{
    push(lst_b, lst_a);
    write(1,"pb\n",3);
}