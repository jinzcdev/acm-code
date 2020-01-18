// https://pintia.cn/problem-sets/16/problems/1086
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

void ShortestDist(MGraph Graph, int dist[], int path[], Vertex S);

int main() {
    int dist[MaxVertexNum], path[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist(G, dist, path, S);

    for (V = 0; V < G->Nv; V++) printf("%d ", dist[V]);
    printf("\n");
    for (V = 0; V < G->Nv; V++) printf("%d ", path[V]);
    printf("\n");

    return 0;
}

MGraph ReadG() {
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    scanf("%d%d", &Graph->Nv, &Graph->Ne);
    for (int i = 0; i < MaxVertexNum; i++)
        for (int j = 0; j < MaxVertexNum; j++) Graph->G[i][j] = INFINITY;
    Vertex u, v;
    for (int i = 0; i < Graph->Ne; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &Graph->G[u][v]);
    }
    return Graph;
}

/* Your function will be put here */
void ShortestDist(MGraph Graph, int dist[], int path[], Vertex S) {
    for (int i = 0; i < Graph->Nv; i++) dist[i] = INFINITY;
    dist[S] = 0;
    path[S] = -1;
    bool vis[MaxVertexNum] = {false};
    while (S != -1) {
        vis[S] = true;
        for (Vertex v = 0; v < Graph->Nv; v++) {
            if (vis[v] == false && Graph->G[S][v] != INFINITY) {
                if (dist[S] + Graph->G[S][v] < dist[v]) {
                    dist[v] = dist[S] + Graph->G[S][v];
                    path[v] = S;
                }
            }
        }
        S = -1;
        for (Vertex v = 0, MIN = INFINITY; v < Graph->Nv; v++) {
            if (vis[v] == false && dist[v] < MIN) {
                S = v;
                MIN = dist[v];
            }
        }
    }
    for (Vertex v = 0; v < Graph->Nv; v++) {
        if (dist[v] == INFINITY) {
            dist[v] = path[v] = -1;
        }
    }
}