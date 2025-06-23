int get_max_bits(t_list *lst)
{
    int max = *(int *)lst->index;
    int max_bits = 0;

    while (lst)
    {
        if (*(int *)lst->index > max)
            max = *(int *)lst->index;
        lst = lst->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

void radix_sort_optimized(t_list **a, t_list **b)
{
    int i, j, size, max_bits;
    size = ft_lstsize(*a);
    max_bits = get_max_bits(*a);

    for (i = 0; i < max_bits; i++)
    {
        j = 0;
        int pushed = 0;
        int rotated = 0;

        while (j < size)
        {
            int num = *(int *)(*a)->index;

            if (((num >> i) & 1) == 0)
            {
                pb(b, a);
                pushed++;
            }
            else
            {
                ra(a);
                rotated++;
            }
            j++;
        }

        // Ramène tout de b vers a
        while (pushed--)
            pa(a, b);

        // Pour éviter rotation excessive : faire ra uniquement si vraiment nécessaire
        // Ici on a déjà fait les rotations nécessaires dans la boucle.

        size = ft_lstsize(*a);
    }
}
