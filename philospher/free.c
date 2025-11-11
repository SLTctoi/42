#include "philo.h"

void free_all(t_rules *rules, t_philo **philos)
{
    int i;

    if (rules->forks)
    {
        i = -1;
        while (++i < rules->nb_philo)
            pthread_mutex_destroy(&rules->forks[i]);
        free(rules->forks);
    }
    pthread_mutex_destroy(&rules->print_mutex);
    pthread_mutex_destroy(&rules->died_mutex);
    if (*philos)
    {
        free(*philos);
        *philos = NULL;
    }
}