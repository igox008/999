#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h> 

char *ft_strchr(char *s, char srch)
{
    for (;*s;s++)
    {
        if (*s == srch)
            return (s);
    }
    return (NULL);
}

bool    ft_ultimate_strchr(char *s, char *srch)
{
    for (int i = 0;srch[i];i++)
    {
        if (!ft_strchr(s, srch[i]))
            return (true);
    }
    return (false);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		t;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	t = ((s1 != NULL) ? strlen(s1) : 0) + ((s2 != NULL) ? strlen(s2) : 0);
	new = (char *)malloc(t + 1);
	if (new == NULL)
		return (NULL);
	while (s1 && s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
    free(s1);
	return (new);
}

int main()
{
    char *prnt = NULL;
    int t;
    scanf("%d", &t);
    for (int i = 0;i < t;i++)
    {
        int len;
        scanf("%d", &len);
        char name[1024];
        scanf(" %[^\n]", name);
        if (!ft_ultimate_strchr(name, "ANSAMBLE"))
            prnt = ft_strjoin(prnt, "LEAVE IT\n");
        else
            prnt = ft_strjoin(prnt, "TAKE IT\n");
    }
    printf("%s", prnt);
    free(prnt);
}