#include <stdio.h>
#include <stdlib.h>
// #include <graph.h>

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

bool TopSort(LGraph Graph, Vertex TopOrder[]);

int main() {
    int i;
    Vertex TopOrder[MaxVertexNum];
    LGraph G = ReadG();

    if (TopSort(G, TopOrder) == true)
        for (i = 0; i < G->Nv; i++) printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");

    return 0;
}

/* Your function will be put here */
bool TopSort(LGraph Graph, Vertex TopOrder[]) {
    int front = 0, tail = 0, cnt = 0, indegree[MaxVertexNum] = {0};
    for (int i = 0; i < Graph->Nv; i++) {
        PtrToAdjVNode p = Graph->G[i].FirstEdge;
        while (p != NULL) {
            indegree[p->AdjV]++;
            p = p->Next;
        }
    }
    for (int i = 0; i < Graph->Nv; i++) {
        if (indegree[i] == 0) {
            TopOrder[tail++] = i;
        }
    }
    while (front != tail) {
        PtrToAdjVNode p = Graph->G[TopOrder[front++]].FirstEdge;
        while (p != NULL) {
            if (--indegree[p->AdjV] == 0) TopOrder[tail++] = p->AdjV;
            p = p->Next;
        }
        cnt++;
    }
    return Graph->Nv == cnt ? true : false;
}