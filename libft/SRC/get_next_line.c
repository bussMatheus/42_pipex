#include "../libft.h"

char	*get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	char		*line;
	int			b_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buff[0] == '\0')
		{
			b_read = read(fd, buff, BUFFER_SIZE);
			if (b_read < 0 && line)
				return (free(line), NULL);
			if (b_read == 0 || (b_read < 0 && !line))
				return (line);
			buff[b_read] = '\0';
		}
		line = ft_strjoin_gnl(line, buff);
		if (!line)
			return (NULL);
		if (cut_remaining(buff))
			break ;
	}
	return (line);
}
/*
int	main()
{
	char *line;
	int fd = open("./file.txt", O_RDONLY);
	int lines = 0;

    while ((line = get_next_line(fd)))
    {
        printf("%d, %s\n", lines++, line);
        free(line);
    }
    close(fd);
    return (0);
}
*/