#include <stdio.h>
#include <stdlib.h>

typedef struct sl
{
	int n;
	int m;
	char *s;
} tl;


int main()
{
	int t;
	scanf("%d", &t);
	tl	*list = malloc(sizeof(tl) * t);
	for (int i = 0;i < t;i++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		char *s = malloc(n + 1);
		scanf("%s", s);
		s[n] = '\0';
		list[i].n = n;
		list[i].m = m;
		list[i].s = s;
	}
	int i = 0;
	int a = 0, b= 0, c= 0, d = 0, e = 0, f =0, g =0;
	int ret = 0;
	while (i < t)
	{
		ret = 0;
		a = 0, b= 0, c= 0, d = 0, e = 0, f =0, g =0;
		for (int j = 0; list[i].s[j];j++)
		{
			switch (list[i].s[j])
			{
				case 'A':
					a++;
					break;
				case 'B':
					b++;
					break;
				case 'C':
					c++;
					break;
				case 'D':
					d++;
					break;
				case 'E':
					e++;
					break;
				case 'F':
					f++;
					break;
				case 'G':
					g++;
					break;
				default:
					break;
			}
		}
		for (int j = 0;j < list[i].m;j++)
		{
			if (--a < 0)
				ret++;
			if (--b < 0)
				ret++;
			if (--c < 0)
				ret++;
			if (--d < 0)
				ret++;
			if (--e < 0)
				ret++;
			if (--f < 0)
				ret++;
			if (--g < 0)
				ret++;
		}
		printf("%d\n", ret);
		i++;
	}
}