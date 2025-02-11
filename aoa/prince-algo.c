#include <stdio.h>
#include <stdlib.h>

int cost[10][10], i, j, min, mincost = 0, ne = 1, n, a, u, b, v;
int visited[10] = {0};  // Initialize visited array

void main() {
    printf("\nNo. of nodes: ");
    scanf("%d", &n);
    
    printf("\nEnter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Replace 0 with infinity (except diagonal)
        }
    }

    printf("\nCost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    printf("\nEdges for MST are:\n");
    visited[1] = 1; // Start from node 1

    while (ne < n) { 
        min = 999;  // Reset min for every iteration
        
        for (i = 1; i <= n; i++) {
            if (visited[i]) {  // Ensure we select an edge from visited nodes
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {  // Ensure j is unvisited
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (!visited[v]) { // Ensure only unvisited node is added
            printf("\nEdge %d: (%d, %d) Cost: %d", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
        }

        cost[a][b] = cost[b][a] = 999; // Mark edge as used
    }

    printf("\nCost of MST is %d\n", mincost);
}

/* Answer
No. of nodes: 4

Enter adjacency matrix:
0 3 0 5
3 0 6 0
0 6 0 9
5 0 9 0

Cost matrix:
999     3       999     5  
3       999     6       999
999     6       999     9  
5       999     9       999

Edges for MST are:

Edge 1: (1, 2) Cost: 3
Edge 2: (1, 4) Cost: 5
Edge 3: (2, 3) Cost: 6
Cost of MST is 14
*/