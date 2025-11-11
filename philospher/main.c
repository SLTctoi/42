#include "philo.h"

// ligne 17 on crée un thread par philo
int main(int ac, char **av)
{
    t_rules rules;
    t_philo *philos;
    int i;

    if (init_all(&rules, &philos, ac, av))
        return (1);
    rules.start_time = get_time(); 
    i = -1;
    while (++i < rules.nb_philo)
        philos[i].last_meal = rules.start_time;
    i = -1;
    while (++i < rules.nb_philo)
        pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]);
    pthread_t monitor;
    pthread_create(&monitor, NULL, monitor_routine, philos);
    i = -1;
    while (++i < rules.nb_philo)
        pthread_join(philos[i].thread, NULL);
    pthread_join(monitor, NULL);
    free_all(&rules, &philos);
    return (0);
}