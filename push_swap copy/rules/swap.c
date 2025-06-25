#include "../push_swap.h"

void    swap(t_list **lst)
{
    t_list *first;
    t_list *second;
    int temp_content;

    if (!lst || !*lst || !(*lst)->next)
        return ;
    first = *lst;
    second = (*lst)->next;

    temp_content = first->content;
    first->content = second->content;
    second->content = temp_content;
}

void    swap_a(t_pile *pile)
{
    if (pile->size_a < 2)
        return ;
    swap(&pile->lst_a);
    write(1,"sa\n",3);
}

void    swap_b(t_pile *pile)
{
    if (pile->size_b < 2)
        return ;
    swap(&pile->lst_b);
    write(1,"sb\n",3);
}

void    swap_a_and_b(t_pile *pile)
{
    if (pile->size_a < 2 || pile->size_b < 2)
        return ;
    swap(&pile->lst_a);
    swap(&pile->lst_b);
    write(1,"ss\n",3);
}