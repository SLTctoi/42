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