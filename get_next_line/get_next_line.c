#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    int     c = 0;
    int     rd = 0;
    char    character;
    char    *line = malloc(100000);
    
    if (BUFFER_SIZE <= 0)
    {
        free(line);
        return (NULL);
    }

    rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
    
    while (rd > 0)
    {
        line[c++] = character;
        if (character == '\n')
            break ;
        rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
    }
    
    line[c] =  '\0';
    
    if (rd == -1 || c == 0 || (!line[c - 1] && !rd))
    {
        free(line);
        return (NULL);
    }
    
    return(line);
}