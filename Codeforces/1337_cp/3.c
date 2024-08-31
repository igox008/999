#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h> 

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

char	**ft_split(char const *s, char c)
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

bool    is_there(char *s, int n)
{
    char **tmp = ft_split(s, ' ');
    for (int i = 0;tmp[i];i++)
    {
        if (atoi(tmp[i]) == n)
            return (true);
    }
    return (false);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    char s[1024];
    scanf(" %[^\n]", s);
    int *p = malloc(sizeof(int) * N);
    int j = 0;
    for (int i = 1;i <= N;i++)
    {
        if (!is_there(s, i))
        {
            p[j] = i;
            j++;
        }
    }
    if (!j)
        printf("All students are present\n");
    else
    {
        for (int i = 0; i < j;i++)
        {
            printf("%d", p[i]);
            if (i + 1 < j)
                printf(" ");
        }
        printf("\n");
    }
}