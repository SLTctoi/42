#include "push_swap.h"

int list_size(t_list *lst)
{
    int count = 0;
    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return count;
}

t_pile init_pile(int ac, char **av)
{
    t_list *lst_a;
    t_pile pile;

    lst_a = NULL;
    parsing(ac, av, &lst_a);
    pile.lst_a = lst_a;
    pile.size_a = list_size(lst_a);
    pile.lst_b = NULL;
    pile.size_b = 0;
    return (pile);
}
int main(int ac, char **av)
{
    t_pile pile;
    if (ac < 2)
        return 1;
    //verif(av);
    pile = init_pile(ac, av);
    sort_chunk(&pile);
    free_pile(&pile);
    return (0);
}

// !!! si c est deja trie ne pas retrier et juste return la listess !!!
// un algo pour 2 arg je change seulement si c est pas deja trié
// un algo pour 3 arg
// un algo pour 4 arg
// un algo pour 5 arg
// un algo pour >5 arg