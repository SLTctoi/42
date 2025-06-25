#include "push_swap.h"

void    simple_sort(int *lst, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (lst[i] > lst[j])
            {
                tmp = lst[i];
                lst[i] = lst[j];
                lst[j] = tmp;
            }
            j++;
        }
        i++;
    }
}
int *sort_tab(t_list *lst, int size)
{
    int *tab;
    int i;

    i = 0;
    tab = malloc(sizeof(int) * size);
    if (!tab)
        return (NULL);
    while (i < size && lst)
    {
        tab[i] = lst->content;
        lst = lst->next;
        i++;
    }
    simple_sort(tab, size);
    return (tab);
}

void    replace_by_index(t_pile *pile)
{
    t_list *tmp;
    int *lst;
    int i;

    lst = sort_tab(pile->lst_a, pile->size_a);
    if (!lst)
        return ;
    tmp = pile->lst_a;
    while (tmp)
    {
        i = 0;
        while (i < pile->size_a)
        {
            if (tmp->content == lst[i])
            {
                tmp->content = i;
                break;
            }
            i++;
        }
        tmp = tmp->next;
    }
    free(lst);
}
int get_max_index(t_list *lst)
{
    int i;
    int index;
    int max;

    if (!lst)
        return (-1);
    i = 1;
    index = 0;
    max = lst->content;
    lst = lst->next;
    while (lst)
    {
        if (lst->content > max)
        {
            max = lst->content;
            index = i;
        }
        lst = lst->next;
        i++;
    }
    return (index);
}
void    push_b_sort(t_pile *pile)
{
    int i;

    while (pile->size_b > 0)
    {
        i = get_max_index(pile->lst_b);
        if (i <= pile->size_b / 2)
        {
            while (i-- > 0) // -0 ?
                rotate_b(pile);
        }
        else
        {
            while (i++ < pile->size_b)
                rrotate_b(pile);
        }
        push_a(pile);
    }
}

int in_chunk(t_pile *pile, int min, int max)
{
    t_list *tmp;

    tmp = pile->lst_a;
    while (tmp)
    {
        if (tmp->content >= min && tmp->content <= max)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}
void    process_chunk(t_pile *pile, int chunk_min, int chunk_max)
{
    while (in_chunk(pile, chunk_min, chunk_max))
    {
        if (pile->lst_a->content >= chunk_min && pile->lst_a->content <= chunk_max)
        {
            push_b(pile);
            if (pile->lst_b->content < (chunk_min + chunk_max) / 2)
                rotate_b(pile);
        }
        else
            rotate_a(pile);
    }
}
void    push_chunk(t_pile *pile, int chunk_count)
{
    int size;
    int chunk_size;
    int chunk_min;
    int chunk_max;

    size = pile->size_a;
    chunk_size = size / chunk_count;
    chunk_min = 0;
    chunk_max = chunk_size;
    while (chunk_min < size)
    {
        process_chunk(pile, chunk_min, chunk_max);
        chunk_min = chunk_max + 1;
        chunk_max += chunk_size;
        if (chunk_max >= size)
            chunk_max = size - 1;
    }
}
void    sort_chunk(t_pile *pile)
{
    replace_by_index(pile);
    if (pile->size_a <= 100)
        push_chunk(pile, 5);
    else
        push_chunk(pile, 10);
    push_b_sort(pile);
}