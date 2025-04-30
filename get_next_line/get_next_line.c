// malloc en fonction de BUFFER_SIZE
// read return -1 si error
// ligne d'avant = derniere ligne si , celle de mtn read return 0
// static var ne se reinitialise pas a chaque appelle 
char *get_next_line(int fd)
{
	char *buffer;
	size_t	bytesRead;

	if (!fd)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	bytesRead = read( fd, buffer, sizeof(buffer) - 1);
	if (bytesRead <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytesRead] = '\0';
	return(buffer);
}
// jextrai le file a la taille du buffer si 
// read dans un boucle pour avoir tout le fichier (quand = 0 = pas de char lu = fin)
{
	while (bytesRead > 0)
	{
		
	}
}