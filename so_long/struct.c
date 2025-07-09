void set_img_map_object(t_map *m, char *map_file)
{
    m->map = parse_map(map_file) // faire une fonction qui parse la map pour la mettre en version [][] et faire les verifs avant aussi
    m->height = 100; // verif quelle taille est le mieux 
    m->width = 100;
    m->object = parse_object(m->map); // faire une fonction qui met les bon char pour les img et calcule le nbre d'entrée, sortie et item
    m->img = parse_img(); // faire un efonction qui creer les img
}