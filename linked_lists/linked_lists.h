#ifndef LINKED_LISTS_H
# define LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list
{
    void	*ptr;
	struct s_list *next;
}	single_list;



#endif
