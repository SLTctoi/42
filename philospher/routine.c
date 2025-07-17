#include "philo.h"

void eating_routine(t_rules *rules, t_philo *philo)
{   
    print_action(philo, "has taken a fork");
    pthread_mutex_lock(&philo->left_fork);
    print_action(philo, "has taken a fork");
    pthread_mutex_lock(&philo->right_fork);
    philo->last_meal = get_time();
    philo->meals_eaten += 1;
    print_action(philo, "is eating");
    usleep(rules->time_to_eat * 1000);
    pthread_mutex_unlock(&philo->left_fork);
    pthread_mutex_unlock(&philo->right_fork);
}

void thinking_routine(t_rules *rules, t_philo *philo)
{
    print_action(philo, "is thinking");
}

void sleeping_routine(t_rules *rules, t_philo *philo)
{
    print_action(philo, "is sleeping");
    usleep(rules->time_to_sleep * 1000);
}
void die_routine(t_rules *rules, t_philo *philo)
{
    pthread_mutex_lock(&rules->died_mutex);
    if ((get_time() - philo->last_meal) > rules->time_to_die)
    {
        print_action(philo, "died");
        rules->someone_died = philo->id;
    }
    pthread_mutex_unlock(&rules->died_mutex);
}
// je dois mettre dans une boucle car cest le thread qui va appeler la fonction
// changer les entrees en void *arg
void routine(t_rules *rules, t_philo *philo)
{
    eating_routine(rules, philo);
    die_routine(rules, philo);
    sleeping_routine(rules, philo);
    die_routine(rules, philo);
    thinking_routine(rules, philo);
    die_routine(rules, philo);
}
