# include <cctype> // std::toupper -> mettre en maj
# include <iostream> // std::cout -> print | std::endl -> pour une new line 

int main(int ac, char **av)
{
    int i;
    int j;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            std::cout << (char)std::toupper(av[i][j]);
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}