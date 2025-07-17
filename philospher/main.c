// quand on pthread_create faut pthread_join ou pthread_detach
#include "philo.h"

int main(int ac, char **av)
{
    t_rules rules;
    t_philo *philos;

    init_all(&rules, philos, ac, av);

    free_all(&rules, philos);
    return (0);
}

// pthread_create(philo->thread , NULL, routine, args = philo
// creer une boucle avec le pthread_create qui lance la fonction routine temps qu il n y a pas de mort.
