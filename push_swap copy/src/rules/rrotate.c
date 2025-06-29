#include "../../include/push_swap.h"
void    rrotate(t_list **lst)
{
    t_list *last;
    t_list *second_last;

    if (!lst || !*lst || !(*lst)->next)
        return ;
    last = *lst;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *lst;
    *lst = last;
}

void rrotate_a(t_pile *pile)
{
    rrotate(&pile->lst_a);
    write(1,"rra\n",4);
}

void rrotate_b(t_pile *pile)
{
    rrotate(&pile->lst_b);
    write(1,"rrb\n",4);
}

void rrotate_a_and_b(t_pile *pile)
{
    rrotate(&pile->lst_a);
    rrotate(&pile->lst_b);
    write(1,"rrr\n",4);
}