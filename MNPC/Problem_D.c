#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

static int	count_w(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cnt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cnt);
}

static char	*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(n + 1);
	if (!new)
		return (NULL);
	while (i < n)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**ft_arr_fail(char **arr, int index)
{
	while (index >= 0)
	{
		free(arr[index]);
		index--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		index;
	int		wc;
	char	**arr;

	wc = count_w(s, c);
	index = -1;
	arr = (char **)malloc((sizeof(char *)) * (wc + 1));
	if (!arr)
		return (NULL);
	while (++index < wc)
	{
		i = 0;
		while (*s && *s == c)
			s++;
		while (*(s + i) != c && *(s + i))
			i++;
		arr[index] = ft_strndup(s, i);
		if (arr[index] == NULL)
			return (ft_arr_fail(arr, index));
		while (*s && *s != c)
			s++;
	}
	arr[index] = NULL;
	return (arr);
}

unsigned long long	ft_atoi(char *str)
{
	int		i;
	int		s;
	long long		rsl;

	i = 0;
	s = 1;
	rsl = 0;
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
		i++;
	}
	return (rsl * s);
}


int main()
{
    char str[256];
    scanf(" %[^\n]", str);

    char **all = ft_split(str, ' ');
    int i = 0;
    for (;all[i]!=NULL;i++){}
    if (i == 3) {
        unsigned long long d[3] = {ft_atoi(all[0]), ft_atoi(all[1]), ft_atoi(all[2])};
        if (d[0] > ULLONG_MAX / d[1] || d[1] > ULLONG_MAX / d[0])
        {
            printf("Yes");
            return 0;
        }
        printf("%s\n", (d[0] * d[1] >= d[2] ? "Yes" : "No"));
    }
}