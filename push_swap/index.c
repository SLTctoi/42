int len_list(t_list *lst)
{
    int count;

    count = 0;
    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return (count);
}

t_list *find_min_index(t_list *lst)
{
    t_list *min_node;

    min_node = NULL;
    while (lst)
    {
        if (!lst->index)
        {
            if (!min_node || *(int *)lst->content < *(int *)min_node->content)
                min_node = lst;
        }
        lst = lst->next;
    }
    return (min_node);
}

void    index(t_list *lst)
{
    int count;
    int i;
    t_list **min_node;

    count = len_list(lst);
    i = 0;
    while (i < count)
    {   
        min_node = find_min_index(lst);
        if (min_node)
        {
            min_node->index = malloc(sizeof(int));
            if (min_node->index)
                *(min_node->index) = i;
    
        }
    i++;
    }
}
