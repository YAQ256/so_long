#include "so_long.h"

void	read_map(t_game *game)
{
	int fd;
	char *line;

	fd = open("./testmap.ber", O_RDONLY);
	line = get_next_line(fd);
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	game->map.line = (ft_strdup_without_nl(line));
	free(line);

	while (line)
	{
		line = get_next_line(fd);
		game->map.line = ft_strjoin_without_nl(game->map.line, line);
		game->map.height++;
	}
	close(fd);
}