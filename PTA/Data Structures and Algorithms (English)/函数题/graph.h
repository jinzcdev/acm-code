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
    }
    return Graph;
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