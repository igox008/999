#include <libc.h>
#include <stdbool.h>
#include <ctype.h>

bool	rot_n(char *str, int n)
{
	int i = 0;
	while (str[i])
	{
		if (isalpha(str[i]))
		{
			int j = 0;
			while (j < n)
			{
				if (tolower(str[i]) + 1 - 'a' > 25)
					str[i] = isupper(str[i]) ? 'A' : 'a';
				else
					str[i]++;
				j++;
			}
		}
		i++;
	}
	return (true);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned long	rsl;

	(i = 0, s = 1, rsl = 0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rsl = (rsl * 10) + (str[i] - 48);
		if (rsl > INT_MAX)
			return (-1);
		i++;
	}
	return (rsl * s);
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (printf("usage ./rot <string> <n to rot>\n"));
	if (!strlen(av[1]) || !strlen(av[2]))
		return (printf("args can't be empty | usage ./rot <string> <n to rot>\n"));
	for (int j = 0;av[2][j];j++)
	{
		if (!isdigit(av[2][j]))
			return (printf("please enter a valid number | usage ./rot <string> <n to rot>\n"));
	}
	int n = ft_atoi(av[2]);
	if (n < 0)
		return (printf("please enter a valid number | usage ./rot <string> <n to rot>\n"));
	else if (n > 25)
		return (printf("please enter a valid number between 0-25 | usage ./rot <string> <n to rot>\n"));
	rot_n(av[1], n);
	printf("\"%s\"\n", av[1]);
	return (0);
}