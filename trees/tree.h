#ifndef TREE_H
# define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

typedef struct s_tree   t_tree;

typedef enum s_enum
{
	ROOT,
	NODE   
}   t_enum;

typedef struct s_tree
{
	char    *content;
	t_tree  *left;
	t_tree  *right;
	t_tree  *prev;
	t_enum	tag;
}   t_tree;


#endif
