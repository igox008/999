#include <libc.h>

char *ultra_strjoin(int n, ...) {
    va_list args;
    va_start(args, n);
    size_t totalLen = 1;

    for (int i = 0; i < n; i++) {
        const char *current_str = va_arg(args, const char *);
        totalLen += strlen(current_str);
    }
    va_end(args);
    char *result = (char *)malloc(totalLen);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    result[0] = '\0';
    va_start(args, n);

    for (int i = 0; i < n; i++) {
        const char *current_str = va_arg(args, const char *);
        strcat(result, current_str);
    }
    va_end(args);
    return result;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (printf("one argument please"), -1);
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (printf("cannot open this file '%s'", av[1]), -1);
    int i = 0;
    int t = 0;
    int len;
    char *file = av[1];
    if ((len = strlen(file)) <= 2 || file[0] == '.')
        return (printf("file name not supported"), -1);
    while (file[i]){if (file[i] == '.'){t = i;}i++;}
    if (strlen(file + t) != 2 || file[t + 1] != 'c')
        return (printf("file extenion not supported"), -1);
    char *obj = strdup(file);
    obj[t] = '\0';
    char flags[] = "gcc -Wall -Wextra -Werror -g ";
    char *cmd = ultra_strjoin(4, flags, file, " -o ", obj);
    // printf("%s", cmd);
    system(cmd);
    free(cmd);
}