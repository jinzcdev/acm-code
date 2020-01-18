// https://pintia.cn/problem-sets/16/problems/706
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
#define MaxVertexNum 10 /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode {
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

void ShortestDist(LGraph Graph, int dist[], Vertex S);

int main() {
    int dist[MaxVertexNum];
    Vertex S, V;
    LGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist(G, dist, S);

    for (V = 0; V < G->Nv; V++) printf("%d ", dist[V]);

    return 0;
}

LGraph ReadG() {
    LGraph g = (LGraph)malloc(sizeof(LGraph));
    for (int i = 0; i < MaxVertexNum; i++) {
        g->G[i].FirstEdge = NULL;
    }
    scanf("%d%d", &g->Nv, &g->Ne);
    Vertex u, v;
    for (int i = 0; i < g->Ne; i++) {
        scanf("%d%d", &u, &v);
        PtrToAdjVNode node = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        node->AdjV = v;
        node->Next = g->G[u].FirstEdge;
        g->G[u].FirstEdge = node;
    }
    return g;
}

/* Your function will be put here */
void ShortestDist(LGraph Graph, int dist[], Vertex S) {
    int INF = 0x7FFFFFFF;
    for (int i = 0; i < Graph->Nv; i++) dist[i] = INF;
    bool vis[MaxVertexNum] = {false};
    dist[S] = 0;
    while (S != -1) {
        vis[S] = true;
        PtrToAdjVNode p = Graph->G[S].FirstEdge;
        while (p != NULL) {
            if (vis[p->AdjV] == false && dist[p->AdjV] > dist[S] + 1) {
                dist[p->AdjV] = dist[S] + 1;
            }
            p = p->Next;
        }
        S = -1;
        int MIN = INF;
        for (Vertex v = 0; v < Graph->Nv; v++) {
            if (vis[v] == false && dist[v] < MIN) {
                S = v;
                MIN = dist[v];
            }
        }
    }
    for (Vertex v = 0; v < Graph->Nv; v++)
        if (dist[v] == 0x7FFFFFFF) dist[v] = -1;
}