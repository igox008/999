#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100005

typedef struct Node {
    long long value;
    long long maxWater;
    long long absorbingPower;
    struct Node* children;
} Node;

Node nodes[MAX_NODES];

void initializeTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i].value = 0;
        nodes[i].maxWater = LLONG_MIN;
        nodes[i].absorbingPower = 0;
        nodes[i].children = NULL;
    }
}

void addEdge(int parent, int child) {
    nodes[parent].children = realloc(nodes[parent].children, (nodes[parent].value + 1) * sizeof(Node));
    nodes[parent].children[nodes[parent].value] = nodes[child];
    nodes[parent].value++;
}

long long fixSinkAndGetMaxWater(Node* node) {
    long long maxWater = 0;

    for (int i = 0; i < node->value; i++) {
        long long childWater = fixSinkAndGetMaxWater(&node->children[i]);
        maxWater += childWater;
    }

    maxWater += node->absorbingPower;

    if (maxWater < 0) {
        maxWater = 0;
    }

    if (maxWater > node->maxWater) {
        node->maxWater = maxWater;
    }

    return maxWater;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        initializeTree();

        for (int i = 1; i <= n; i++) {
            scanf("%lld", &nodes[i].absorbingPower);
        }

        for (int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            addEdge(x, y);
        }

        fixSinkAndGetMaxWater(&nodes[1]);

        printf("%lld\n", nodes[1].maxWater);
    }

    return 0;
}
