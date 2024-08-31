#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list
{
    char *s;
    int cnt;
    int index;
    struct s_list *next;
}   t_list;

t_list *new_node(char *s)
{
    static int i;
    t_list  *ret= malloc(sizeof(t_list));
    if (!ret)
        return (NULL);
    ret->s = strdup(s);
    ret->cnt = 1;
    ret->index = i;
    ret->next = NULL;
    i++;
    return (ret);
}

void    add_back(t_list **head, t_list *new)
{
    if (!new)
        return ;
    if (!*head)
        *head = new;
    else
    {
        t_list *tmp = *head;
        for (;tmp && tmp->next;tmp = tmp->next)
            ;
        tmp->next = new;
    }
}

int make_list(t_list **head, char *s)
{
    t_list *list = *head;
    while (list)
    {
        if (!strcmp(list->s, s))
            return (list->cnt += 1, 1);
        list = list->next;
    }
    add_back(head, new_node(s));
    return (0);
}

void free_list(t_list **head)
{
    t_list *tmp = *head;
    t_list *cur;

    while (tmp)
    {
        cur = tmp->next;
        free(tmp->s);
        free(tmp);
        tmp = cur;
    }
}
int list_size(t_list *list)
{
    int i = 0;
    for (;list;list = list->next)
        i++;
    return (i);
}

int get_max_repeat(t_list **head, int *size)
{
    int i = -1;
    char *s = NULL;
    t_list *list = *head;
    while (list)
    {
        if (list->cnt > i)
            i = list->cnt;
        list = list->next;
    }
    list = *head;
    while (list)
    {
        if (list->cnt == i)
        {
            *size += 1;
            s = list->s;
        }
        list = list->next;
    }
    if (*size == 1)
    {
        printf("%s %d\n", s, i);
        free_list(head);
        exit(0);
    }
    return (i);
}


int main()
{
    t_list *head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        char s[256];
        scanf("%s", s);
        make_list(&head, s);
    }
    int size = 0;
    int max_repeat = get_max_repeat(&head, &size);
    char **arr = malloc(size * sizeof(char *));
    if (!arr)
        return (0);
    t_list *tmp = head;
    int j = 0;
    while (tmp)
    {
        if (tmp->cnt == max_repeat)
            arr[j++] = tmp->s;
        tmp = tmp->next;
    }
    char *prnt = arr[0];
    for (int i = 1;i < size;i++)
    {
        if (strcmp(arr[i], prnt) > 0)
            prnt = arr[i];
    }
    printf("%s %d\n", prnt, max_repeat);
    free(arr);
    free_list(&head);
}