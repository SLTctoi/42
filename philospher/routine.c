#include "philo.h"

void eating_routine(t_philo *philo)
{ 
    pthread_mutex_lock(philo->left_fork);
    print_action(philo, "has taken a fork");
    pthread_mutex_lock(philo->right_fork);
    print_action(philo, "has taken a fork");
    print_action(philo, "is eating");
    pthread_mutex_lock(&philo->rules->died_mutex);
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->rules->died_mutex);
    ft_usleep(philo->rules->time_to_eat);
    pthread_mutex_lock(&philo->rules->died_mutex);
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->rules->died_mutex);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void sleeping_routine(t_philo *philo)
{
    print_action(philo, "is sleeping");
    ft_usleep(philo->rules->time_to_sleep);
}

void thinking_routine(t_philo *philo)
{
    print_action(philo, "is thinking");
}

void *philosopher_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->rules->nb_philo == 1)
    {
        print_action(philo, "has taken a fork");
        ft_usleep(philo->rules->time_to_die);
        return (NULL);
    }
    if (philo->id % 2 == 1)
        thinking_routine(philo);
    while (1)
    {
        pthread_mutex_lock(&philo->rules->died_mutex);
        if (philo->rules->someone_died)
        {
            pthread_mutex_unlock(&philo->rules->died_mutex);
            break;
        }
        if (philo->rules->meals_required != -1 && 
            philo->meals_eaten >= philo->rules->meals_required)
        {
            pthread_mutex_unlock(&philo->rules->died_mutex);
            break;
        }
        pthread_mutex_unlock(&philo->rules->died_mutex);
        eating_routine(philo);
        sleeping_routine(philo);
        thinking_routine(philo);
    }
    return (NULL);
}
