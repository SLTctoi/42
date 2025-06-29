#include "../include/push_swap.h"

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
            {
                if (pile->lst_a && (pile->lst_a->content < chunk_min || pile->lst_a->content > chunk_max))
                {
                    rotate_a_and_b(pile);
                    continue;
                }
                rotate_b(pile);
            }
            if (pile->lst_b->next)
            {
                if (pile->lst_b->content < pile->lst_b->next->content)
                    swap_b(pile);
            }
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
        push_chunk(pile, 9);
    push_b_sort(pile);
}