#include <libc.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h>

bool	check_name(char *filename)
{
	char	res[] = ":/?*\"'<>|";
	for (int i = 0;res[i];i++)
	{
		if (strchr(filename, res[i]) != NULL)
			return (printf("%c can't be in a filename\n", res[i]), false);
	}
	return (true);
}

bool    parse(int ac, char **av)
{
	char	*filename;
	char	*tmp;

	if (ac == 1)
		return (printf("the program need one argument!!!\nusage :\t\tmkheader {name of header}\n"), false);
	else if (ac != 2)
		return (printf("too much args, the program need only one argument!!!\nusage :\t\tmkheader {name of header}\n"), false);
	filename = av[1];
	if (strlen(filename) > 256)
		return (printf("filename too long\n"), false);
	if (!check_name(filename))
		return (false);
	tmp = strchr(filename, '.');
	if (!tmp || !tmp[1] || strlen(tmp) > 2 || tmp[1] != 'h')
		return (printf("the file must have the extension `.h`!\n"));
	return (true);
}

void	convert_to_header_guard(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		if (*str == '.')
			*str = '_';
		str++;
	}
}

void	write_to_file(FILE *file, char *guard)
{
	fprintf(file, "#ifndef %s\n", guard);
	fprintf(file, "# define %s\n\n", guard);
	fprintf(file, "#include <stdio.h>\n");
	fprintf(file, "#include <stdlib.h>\n");
	fprintf(file, "#include <stdbool.h>\n");
	fprintf(file, "#include <unistd.h>\n");
	fprintf(file, "#include <limits.h>\n\n");
	fprintf(file, "\n\n\n#endif\n");
}

int main(int ac, char **av)
{
	char	*filename;
	char	*guard;
	int		fd;
	FILE	*file;

	if (!parse(ac, av))
		return (1);
	filename = av[1];
	guard = strdup(filename);
	if (!guard)
		return (printf("an error occur while running the program (probably you ran out of memory)\n"), 1);
	convert_to_header_guard(guard);
	if (access(filename, F_OK) != -1) // check if exist
	{
		char	answer[5];
		printf("the file is already exist do you wanna override it content (yes or no) : ");
		scanf("%5s", answer);
		if (!strcasecmp(answer, "yes"))
		{
			fd = open(filename, O_RDWR | O_TRUNC);
			if (fd == -1)
			{
				if (errno == EACCES)
					printf("Error opening file: Permission denied.\n");
				else
					printf("Error opening file: %s\n", strerror(errno));
				return (free(guard), 1);
			}
			(close(fd), file = fopen(filename, "w"));
			if (file == NULL)
			{
				fprintf(stderr, "Error opening file: %s\n", strerror(errno));
				return (free(guard), 1);
			}
			write_to_file(file, guard);
			printf("file modified successfuly (IGO was here LOL!)\n");
		}
		else
			return (free(guard), 1);
	}
	else
	{
		fd = open(filename, O_CREAT | O_RDWR, 0644);
		if (fd == -1)
			return (printf("Error opening file: %s\n", strerror(errno)), free(guard), 1);
		(close(fd), file = fopen(filename, "w"));
		if (file == NULL)
		{
			fprintf(stderr, "Error opening file: %s\n", strerror(errno));
			return (free(guard), 1);
		}
		write_to_file(file, guard);
		printf("file created successfuly (IGO was here LOL!)\n");
	}
	return (free(guard), 0);
}