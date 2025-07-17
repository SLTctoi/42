#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_rules
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int meals_required;
    int someone_died;
    long start_time;
    pthread_mutex_t died_mutex;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
}       t_rules;

typedef struct s_philo
{
    int id;
    int meals_eaten;
    long last_meal;
    pthread_t thread; // a initialiser 
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_rules *rules;
} t_philo;

// utils
long get_time(void);
int ft_atoi(const char **str);
void print_action(t_philo *philo, char *action);

// init
int init_all(t_rules *rules, t_philo **philos, int ac, char **av);

// routine
int routine(t_rules *rules, t_philo *philo);
void die_routine(t_rules *rules, t_philo *philo);
void sleeping_routine(t_rules *rules, t_philo *philo);
void thinking_routine(t_rules *rules, t_philo *philo);
void eating_routine(t_rules *rules, t_philo *philo);

// free
void free_all(t_rules *rules, t_philo **philos)
