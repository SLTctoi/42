#include "push_swap.h"

void    free_pile(t_pile *pile)
{
    free_list(pile->lst_a);
    free_list(pile->lst_b);
}
void    free_list(t_list *lst)
{
    t_list *temp;

    while (lst)
    {
        temp = lst->next;
        free(lst);
        lst = temp;
    }
}
// jsp quand l utilsier 
void    free_split(char **tab)
{
    int i;

    if (!tab)
        return ;
    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}