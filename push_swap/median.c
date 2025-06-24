void quick_swap(t_list *lst_a, t_list *lst_b)
{
    int *temp;

    temp = lst_a->index;
    lst_a->index = lst_b->index;
    lst_b->index = temp;
}

t_list *tail_list(t_list *lst)
{
    while (lst && lst->next)
        lst = lst->next;
    return (lst);
}
t_list *partition(t_list *low, t_list *high)
{
    int pivot;
    t_list *i;
    t_list *j;

    pivot = *(high->index);
    i = low;
    j = low;
    while (j != high)
    {
        if(*(j->index) <= pivot)
        {
            quick_swap(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swap(i, high);
    return (i);
}
void quick_sort(t_list *low, t_list *high)
{
    t_list *i;
    if (high && low != high && low != high->next)
    {
        i = partition(low, high);
        quick_sort(low, i);
        quick_sort(i->next, high);
    }
}