int main(int ac, char **av)
{
    t_list pile_a;
    int i;

    verif(av);
    i = 1;
    while (i < ac)
        parsing(av[i],pile_a);
    return (0);
}

// !!! si c est deja trie ne pas retrier et juste return la listess !!!
// un algo pour 2 arg je change seulement si c est pas deja trié
// un algo pour 3 arg
// un algo pour 4 arg
// un algo pour 5 arg
// un algo pour >5 arg