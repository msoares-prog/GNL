# Get Next Line 42SP
![](https://img.shields.io/badge/Language-C-blue)
![](https://img.shields.io/badge/School-42-orange)
## Reading a line on a fd is way too tedious

### Description
The aim of this project is to make a function that returns a lineending with a newline, read from a file descriptor. For deeper understanding of the project aims, take a look at this [link](https://github.com/msoares-prog/GNL/blob/master/GNL-subject-en.pdf).

### Return Values

| Value | Retun                          |
|-------|--------------------------------|
|   1   | When it reads a line           |
|   0   | when it finished reading a file|
|  -1   | when an error occurs           |


### Download
Feel free to download the project:
```
git clone https://github.com/msoares-prog/ft_printf.git
```

### Using The Program
Compile the program:
```
gcc -Wall -Wextra -Werror get_next_line.h get_next_line_ultils.c get_next_line.c -o GNL
```
To ```run``` the program:
```
./GNL [input file]
```

### Example of Usage
```
#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		i;
	int		fd;
	char		*line;

	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
		close(fd);
	}
	return (0);
}
```

#### Author
Msoares - [GitHub](https://github.com/msoares-prog/)