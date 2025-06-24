int    median_moove(t_list **lst_a, t_list **lst_b)
{
    int mediane;

    mediane = median(*lst_a);
    while (*lst_a)
    {
        if (*((*lst_a)->index) < mediane)
            push_b(lst_b, lst_a);
        else
            rotate_a(lst_a);
    }
    return (mediane);
}
void nbr_median_moove(t_list **lst_a, t_list **lst_b)
{
    int *median_count ;
    int *count ;
    int i;

    i = 0;
    count = malloc(sizeof(int) * (int_log2(ft_lstsize(*lst_a) + 2)));
    if (!count)
        return ;
    while (ft_lstsize(*lst_a) > 2)
    {
        count[i] = median_moove(lst_a, lst_b);
        i++;
    }
    count[i] = -1;
    if (*((*lst_a)->index) > *((*lst_a)->next->index))
        swap_a(lst_a);
    free(count)
}
///////////////////////attention modifié lst_new pour push aussi la val de l'index !!!!!!!!!!!!!