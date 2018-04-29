#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "graph.h"


int main() {
  int vertex_no = 10;
  HGraph g = getGraph(vertex_no);
  /*addEdgeToGraph(g, 0, 1);
  addEdgeToGraph(g, 1, 2);
  addEdgeToGraph(g, 2, 3);
  addEdgeToGraph(g, 3, 0);*/

  addEdgeToGraph(g, 0, 1);
  addEdgeToGraph(g, 0, 2);
  
  addEdgeToGraph(g, 1, 0);
  addEdgeToGraph(g, 1, 3);
  addEdgeToGraph(g, 1, 4);
  
  addEdgeToGraph(g, 2, 0);
  addEdgeToGraph(g, 2, 5);
  addEdgeToGraph(g, 2, 6);
  
  addEdgeToGraph(g, 3, 1);
  addEdgeToGraph(g, 3, 7);
  
  addEdgeToGraph(g, 4, 1);
  addEdgeToGraph(g, 4, 7);

  addEdgeToGraph(g, 5, 2);
  addEdgeToGraph(g, 5, 8);

  addEdgeToGraph(g, 6, 2);
  addEdgeToGraph(g, 6, 8);
  
  addEdgeToGraph(g, 7, 3);
  addEdgeToGraph(g, 7, 4);
  addEdgeToGraph(g, 7, 9);
  
  addEdgeToGraph(g, 8, 5);
  addEdgeToGraph(g, 8, 6);
  addEdgeToGraph(g, 8, 9);
  
  addEdgeToGraph(g, 9, 7);
  addEdgeToGraph(g, 9, 8);



  printGraph(g);
  dfs(g, 0);
  bfs(g, 0);


  return 0;
}
