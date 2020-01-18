// https://pintia.cn/problem-sets/16/problems/707
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
    WeightType Graph[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG(); /* details omitted */

void ShortestDist(MGraph Graph, int dist[], Vertex S);

int main() {
    int dist[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist(G, dist, S);

    for (V = 0; V < G->Nv; V++) printf("%d ", dist[V]);

    return 0;
}

MGraph ReadG() {
    MGraph Graph = (MGraph)malloc(sizeof(MGraph));

    scanf("%d%d", &Graph->Nv, &Graph->Ne);
    for (int i = 0; i < Graph->Nv; i++)
        for (int j = 0; j < Graph->Nv; j++) Graph->Graph[i][j] = INFINITY;
    Vertex u, v;
    for (int i = 0; i < Graph->Ne; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &Graph->Graph[u][v]);
    }
    return Graph;
}

/* Your function will be put here */
void ShortestDist(MGraph Graph, int dist[], Vertex S) {
    for (int i = 0; i < Graph->Nv; i++) dist[i] = INFINITY;
    dist[S] = 0;
    bool vis[MaxVertexNum] = {false};
    while (1) {
        int u = -1, MIN = INFINITY;
        for (Vertex v = 0; v < Graph->Nv; v++) {
            if (vis[v] == false && dist[v] < MIN) {
                u = v;
                MIN = dist[v];
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (Vertex v = 0; v < Graph->Nv; v++) {
            if (vis[v] == false && Graph->Graph[u][v] != INFINITY) {
                if (dist[u] + Graph->Graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + Graph->Graph[u][v];
                }
            }
        }
    }
    for (Vertex v = 0; v < Graph->Nv; v++) {
        if (dist[v] == INFINITY) dist[v] = -1;
    }
}