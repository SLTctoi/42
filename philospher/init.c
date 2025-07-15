
static int init_rules(t_rules *rules, t_philo **philos, int ac, char **av);
static void init_philos(t_rules *rules, t_philo **philos);

int init_all(t_rules *rules, t_philo **philos, int ac, char **av)
{
    if (ac < 5 || ac > 6)
    {
        write(2, "Error: Bad arguments\n", 21);
        return (0);
    }
    if (!init_rules(rules, philos, ac, av))
    {
        write(2, "Error: Initialization failed\n", 29);
        return (0);
    }
    init_philos(rules, philos);
    return (1);
}
static int init_rules(t_rules *rules, t_philo **philos, int ac, char **av)
{
    int i;

    rules->nb_philo = ft_atoi(av[1]);
    rules->time_to_die = ft_atoi(av[2]);
    rules->time_to_eat = ft_atoi(av[3]);
    rules->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        rules->meals_required = ft_atoi(av[5]);
    else
        rules->meals_required = -1;
    rules->someone_died = 0;
    rules->start_time = get_time();
    rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
    if (!rules->forks)
        return (0);
    *philos = malloc(sizeof(t_philo) * rules->nb_philo);
    if (!*philos)
        return (0);
    i = -1;
    while (++i < rules->nb_philo)
        if(pthread_mutex_init(&rules->forks[i], NULL) != 0)
            return (0);
    if (pthread_mutex_init(&rules->print_mutex, NULL) != 0)
        return (0);
    return (1);
}
static void init_philos(t_rules *rules, t_philo **philos)
{
    int i;

    i = 0;
    while (i < rules->nb_philo)
    {
        (*philos)[i].id = i;
        (*philos)[i].meals_eaten = 0;
        (*philos)[i].last_meal = rules->start_time;
        (*philos)[i].left_fork = &rules->forks[i];
        (*philos)[i].right_fork = &rules->forks[(i + 1) % rules->nb_philo];
        (*philos)[i].rules = rules;
        i++;
    }
}
