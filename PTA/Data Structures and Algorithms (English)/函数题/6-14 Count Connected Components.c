// https://pintia.cn/problem-sets/16/problems/962
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

int CountConnectedComponents(LGraph Graph);

int Count(LGraph Graph);
int main() {
    LGraph G = ReadG();
    printf("%d\n", Count(G));

    return 0;
}

LGraph ReadG() {
    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
    scanf("%d%d", &Graph->Nv, &Graph->Ne);
    for (int i = 0; i < MaxVertexNum; i++) Graph->G[i].FirstEdge = NULL;
    Vertex u, v;
    for (int i = 0; i < Graph->Ne; i++) {
        scanf("%d%d", &u, &v);
        PtrToAdjVNode q = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        q->AdjV = v;
        q->Next = Graph->G[u].FirstEdge;
        Graph->G[u].FirstEdge = q;

        PtrToAdjVNode p = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        p->AdjV = u;
        p->Next = Graph->G[v].FirstEdge;
        Graph->G[v].FirstEdge = p;
    }
    return Graph;
}

/* Your function will be put here */
bool vis[MaxVertexNum] = {false};
void dfs(LGraph Graph, int u) {
    vis[u] = true;
    for (PtrToAdjVNode p = Graph->G[u].FirstEdge; p != NULL; p = p->Next) {
        if (vis[p->AdjV] == false) {
            dfs(Graph, p->AdjV);
        }
    }
}
int CountConnectedComponents(LGraph Graph) {
    int cnt = 0;
    for (int u = 0; u < Graph->Nv; u++) {
        if (vis[u] == false) {
            dfs(Graph, u);
            cnt++;
        }
    }
    return cnt;
}
int CountConnectedComponentsByBFS(LGraph Graph) {
    bool vis[MaxVertexNum] = {false};
    int cnt = 0;
    for (int u = 0; u < Graph->Nv; u++) {
        if (vis[u] == false) {
            int front = 0, tail = 0, q[MaxVertexNum];
            q[tail++] = u;
            while (front != tail) {
                int now = front++;
                vis[now] = true;
                PtrToAdjVNode p = Graph->G[q[now]].FirstEdge;
                while (p != NULL) {
                    if (vis[p->AdjV] == false) {
                        q[tail++] = p->AdjV;
                        vis[p->AdjV] = true;
                    }
                    p = p->Next;
                }
            }
            cnt++;
        }
    }
    return cnt;
}