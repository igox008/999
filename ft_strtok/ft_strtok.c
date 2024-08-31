#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *join_char(char *str, char c)
{
	int len = (!str) ? 0 : strlen(str);
	len++;
	char *ret = malloc(len + 1);
	if (!ret)
		return (perror("malloc"), free(str), NULL);
	int i = -1;
	while (str && str[++i])
		ret[i] = str[i];
	ret[i++] = c;
	ret[i] = '\0';
	free(str);
	return (ret);
}

char *ft_strtok(char *str, char *del)
{
	char *ret;
	static int  i;
	static char	*hold_str;

	ret = NULL;
	if (!del)
		return (NULL);
	if (i == 0 && !str)
		return (NULL);
	if (!hold_str)
	{
		hold_str = strdup(str);
		if (!hold_str)
			return (perror("malloc"), NULL);
	}
	else if (str && strcmp(hold_str, str))
	{
		free(hold_str);
		hold_str = strdup(str);
		if (!hold_str)
			return (perror("malloc"), NULL);
	}
	if (i > 0 && !str)
	{
		while (hold_str[i] && strchr(del, hold_str[i]))
			i++;
		while (hold_str[i] && !strchr(del, hold_str[i]))
		{
			ret = join_char(ret, hold_str[i]);
			if (!ret)
				return (NULL);
			i++;
		}
	}
	else
	{
		while (str[i] && strchr(del, str[i]))
			i++;
		while (str[i] && !strchr(del, str[i]))
		{
			ret = join_char(ret, str[i]);
			if (!ret)
				return (NULL);
			i++;
		}
	}
	return (ret);
}
// int main()
// {
//     char s[] = " efeffre \t\t  dsfsfdsf\t";
//     char *tok = ft_strtok(s, " ");
//     printf(":%s:\n", tok);
//     tok = ft_strtok(NULL, "");
//     printf(":%s:\n", tok);
// }