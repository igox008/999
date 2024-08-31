#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

typedef struct {
    int node;
    int power;
} Edge;

Edge tree[MAX_NODES];
int adjacency[MAX_NODES][2];
int absorbingPower[MAX_NODES];
int totalWater[MAX_NODES];

void dfs(int node, int parent) {
    int i;
    totalWater[node] = absorbingPower[node];
    for (i = adjacency[node][0]; i <= adjacency[node][1]; i++) {
        int child = tree[i].node;
        if (child != parent) {
            dfs(child, node);
            totalWater[node] += totalWater[child];
        }
    }
}

void calculateMaxWater(int node, int parent, int maxWater) {
    int i;
    maxWater = maxWater > totalWater[node] ? maxWater : totalWater[node];
    for (i = adjacency[node][0]; i <= adjacency[node][1]; i++) {
        int child = tree[i].node;
        if (child != parent) {
            int newMaxWater = maxWater + tree[i].power;
            calculateMaxWater(child, node, newMaxWater);
        }
    }
}

int main() {
    int T, i, j;
    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        for (j = 1; j <= N; j++) {
            scanf("%d", &absorbingPower[j]);
            adjacency[j][0] = -1;
            adjacency[j][1] = -1;
        }

        for (j = 1; j <= N - 1; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            tree[j].node = y;
            tree[j].power = absorbingPower[y];
            if (adjacency[x][0] == -1) {
                adjacency[x][0] = j;
            } else {
                adjacency[x][1] = j;
            }
        }

        dfs(1, 0);
        calculateMaxWater(1, 0, 0);

        printf("%d\n", totalWater[1]);
    }

    return 0;
}