#ifndef GRAPH_H
#define GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* HGraph;

HGraph getGraph(const int count);
void addEdgeToGraph(HGraph g, const int from, const int to);
void delEdgeInGraph(HGraph g, const int from, const int to);
void printGraph(HGraph g);
void dfs(HGraph g, int start);
void bfs(HGraph g, int start);
void delGraph(HGraph g);

void testGraph(HGraph g);

#ifdef __cplusplus
}
#endif

#endif
