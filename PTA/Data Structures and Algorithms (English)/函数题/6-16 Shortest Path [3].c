// https://pintia.cn/problem-sets/16/problems/1085
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
#define INFINITY 1000000
#define MaxVertexNum 10 /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG(); /* details omitted */

void ShortestDist(MGraph Graph, int dist[], int count[], Vertex S);

int main() {
    int dist[MaxVertexNum], count[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist(G, dist, count, S);

    for (V = 0; V < G->Nv; V++) printf("%d ", dist[V]);
    printf("\n");
    for (V = 0; V < G->Nv; V++) printf("%d ", count[V]);
    printf("\n");

    return 0;
}

MGraph ReadG() {
    MGraph g = (MGraph)malloc(sizeof(struct GNode));
    scanf("%d%d", &g->Nv, &g->Ne);
    for (int i = 0; i < MaxVertexNum; i++)
        for (int j = 0; j < MaxVertexNum; j++) g->G[i][j] = INFINITY;
    Vertex u, v;
    for (int i = 0; i < g->Ne; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &g->G[u][v]);
    }
    return g;
}

/* Your function will be put here */
void ShortestDist(MGraph Graph, int dist[], int count[], Vertex S) {
    bool vis[MaxVertexNum] = {false};
    for (int i = 0; i < Graph->Nv; i++) {
        dist[i] = INFINITY;
        count[i] = 0;
    }
    dist[S] = 0;
    count[S] = 1;
    int n = Graph->Nv;
    while (1) {
        int u = -1, MIN = INFINITY;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && dist[j] < MIN) {
                u = j;
                MIN = dist[j];
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && Graph->G[u][v] != INFINITY) {
                if (dist[u] + Graph->G[u][v] < dist[v]) {
                    dist[v] = dist[u] + Graph->G[u][v];
                    count[v] = count[u];
                } else if (dist[u] + Graph->G[u][v] == dist[v]) {
                    count[v] += count[u];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INFINITY) {
            dist[i] = -1;
            count[i] = 0;
        }
    }
}


/*
8 11
0 4 5
0 7 10
1 7 30
3 0 40
3 1 20
3 2 100
3 7 70
4 7 5
6 2 1
7 5 3
7 2 50
3

40 20 100 0 45 53 -1 50
1 1 4 1 1 3 0 3
*/