#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "fcntl.h"

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *line;
	int i;
	while ((i = get_next_line(fd, &line, 45)))
	{
		printf("i = %d %s\n", i, line);
		free(line);
	}
	printf("i = %d %s\n", i, line);
	free(line);
	return (0);
}
