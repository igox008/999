#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_game
{
	char *move;
	struct s_game *next;
}   t_game;

t_game	*last_node(t_game *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}

t_game  *new_node(char *move, t_game **head)
{
	t_game  *new = malloc(sizeof(t_game));
	if (!new)
		return (NULL);
	new->move = strdup(move);
	new->next = NULL;
	if (!*head)
		*head = new;
	else
		last_node(*head)->next = new;
	return (new);
}

void	print_move(char *track, int pos)
{
	char *tmp = track + pos;
	if (*tmp == '.' && *(tmp + 1) == '#')
		printf("UP\n");
	else
	{
		int len = 0;
		for (int i = 0;tmp[i] && tmp[i] != '#';i++)
			len++;
		if (len >= 3)
			printf("RIGHT\n");
		else if (len == 2)
			printf("DOWN\n");
		else
			printf("LEFT\n");
	}
}

int main()
{
	int player_idx;
	scanf("%d", &player_idx);
	int nb_games;
	scanf("%d", &nb_games); fgetc(stdin);


	t_game *head = NULL;	
	while (1) {
		for (int i = 0; i < 3; i++) {
			char score_info[65];
			scanf("%[^\n]", score_info); fgetc(stdin);
		}
		char gpu[nb_games][65];
		for (int i = 0; i < nb_games; i++)
		{
			int reg_0;
			int reg_1;
			int reg_2;
			int reg_3;
			int reg_4;
			int reg_5;
			int reg_6;
			scanf("%s%d%d%d%d%d%d%d", gpu[i], &reg_0, &reg_1, &reg_2, &reg_3, &reg_4, &reg_5, &reg_6); fgetc(stdin);
			print_move(gpu[i], (player_idx == 0) ? reg_0 : ((player_idx == 1) ? reg_1 : reg_2));
		}
	}

	return 0;
}