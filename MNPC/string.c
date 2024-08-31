#include <stdio.h>
#include <string.h>

int main() {
    int n[10005];
    int i = 0;
    char S[10005];
    scanf("%s", S);

    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type;
        scanf("%d", &type);

        if (type == 0) {
            int id;
            char c;
            scanf("%d %c", &id, &c);
            S[id - 1] = c;
        } else if (type == 1) {
            char P[21];
            scanf("%s", P);
            int len_S = strlen(S);
            int len_P = strlen(P);
            int index = -1;
            for (int i = 0; i <= len_S - len_P; ++i) {
                if (strncmp(S + i, P, len_P) == 0) {
                    index = i + 1;
                    break;
                }
            }
            n[i] = index;
            i++;
            n[i] = -1337;
        }
    }
    i = 0;
    while (n[i] != -1337)
    {
        printf("%d\n", n[i]);
        i++;
    }
    return 0;
}
