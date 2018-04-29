#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

typedef struct vertex {
  int name;
  struct vertex *next;
} Vertex;

Vertex *getVertex(int name) {
  Vertex *v = (Vertex*)malloc(sizeof(Vertex));
  v->name = name;
  v->next = NULL;
  return v;
}

void freeVertex(Vertex *v) {
  free(v);
}

typedef struct _Graph {
  int count;
  Vertex **vertices;
} Graph;

HGraph getGraph(const int count) {
  Graph *g = (Graph*)malloc(sizeof(Graph));
  g->count = count;
  g->vertices = (Vertex**)malloc(count * sizeof(Vertex*));
  int i;
  for(i = 0; i < count; i++ ) {
    g->vertices[i] = NULL;
  }
  return ((void*)g);
}

void addEdgeToGraph(HGraph g, const int from, const int to) {
  if(!g) {
    printf("Please input legit pointer!\n");
    return;
  }
  
  Graph *gptr = (Graph*)g;
  if( to >= gptr->count || from >= gptr->count) {
    printf("sorry! the vertices you input don't exist!!\n");
    return;
  }
  Vertex **found = &(gptr->vertices[from]);
  while((*found) != NULL) {
    if( ((*found)->name) == to) {
      break;
    }
    found = &((*found)->next);
  }
  if( (*found) ) {
    printf("Sorry! this edge is exited!!\n");
  } else {
    (*found) = getVertex(to);
  }
}

void delEdgeInGraph(HGraph g, const int from, const int to) {
  if(!g) {
    printf("Please input legit pointer!\n");
    return;
  }
  
  Graph *gptr = (Graph*)g;
  if( to >= gptr->count || from >= gptr->count) {
    printf("sorry! the vertices you input don't exist!!\n");
    return;
  }
   
  Vertex **found = &(gptr->vertices[from]);
  while((*found) != NULL) {
    if( ((*found)->name) == to) {
      break;
    }
    found = &((*found)->next);
  }
  if( !(*found) ) {
    printf("Sorry! this edge is not exited!!\n");
    return;
  } else {
    Vertex *temp = (*found);
    (*found) = (*found)->next;
    freeVertex(temp);
  }

}

void dfs(HGraph g, int start) {
  if(!g) {
    printf("Please input legit pointer!\n");
    return;
  }
  Graph *gptr = (Graph*)g;
  if(start >= gptr->count) {
    printf("The start vertex you input doesn't exist\n");
    return;
  }

  int *isVisited = (int*)malloc(sizeof(int)*gptr->count);
  for(int i = 0; i < gptr->count; i++) 
    isVisited[i] = 0;

  Vertex *iter;
  HStack s = getStack();
  pushStack(s, start);
  
  printf("DFS Visit Sequential: ");
 
  while(isStackEmpty(s) == 0) {
    int popVertex = popStack(s);
    if( isVisited[popVertex] == 0) {
      printf("%d, ", popVertex);
      iter = gptr->vertices[popVertex];
      while(iter) {
        pushStack(s, iter->name);
        iter = iter->next;
      }
      isVisited[popVertex] = 1;
    }
  }
  printf("\n");

  free(isVisited);
  delStack(s);
  s = NULL;
}

void bfs(HGraph g, int start) {
  if(!g) {
    printf("Please input legit pointer!\n");
    return;
  }
  Graph *gptr = (Graph*)g;
  if(start >= gptr->count) {
    printf("The start vertex you input doesn't exist\n");
    return;
  }

  int *isVisited = (int*)malloc(sizeof(int)*gptr->count);
  for(int i = 0; i < gptr->count; i++) 
    isVisited[i] = 0;

  Vertex *iter;
  HQueue q = getQueue();
  enQueue(q, start);
  
  printf("BFS Visit Sequential: ");

  while(isQueueEmpty(q) == 0) {
    int outVertex = deQueue(q);
    if( isVisited[outVertex] == 0) {
      printf("%d, ", outVertex);
      iter = gptr->vertices[outVertex];
      while(iter) {
        enQueue(q, iter->name);
        iter = iter->next;
      }
      isVisited[outVertex] = 1;
    }
  }
  printf("\n");
  free(isVisited);
  deleteQueue(q);
  q = NULL;
}

void printGraph(HGraph g) {
  if(!g) {
    printf("Please input legit pointer!\n");
    return;
  }
  
  Graph *gptr = (Graph*)g;
  printf("<<<<<The Graph>>>>>\n");
  int i;
  Vertex *iter;
  for(i = 0; i < gptr->count; i++) {
    printf("%d connected to: ", i);
    iter = gptr->vertices[i];
    while(iter != NULL) {
      printf("%d, ", iter->name);
      iter = iter->next;
    }
    printf("\n");
  }
}

void delGraph(HGraph g) {
  if(!g) {
    printf("Please input legit pointer!\n");
    return;
  }

  Graph *gptr = (Graph*)g;
  int i;
  Vertex **pptr;
  Vertex *temp;
  for(i = 0; i < gptr->count; i++) {
    pptr = &(gptr->vertices[i]);
    while( (*pptr) != NULL) {
      temp = (*pptr);
      (*pptr) = (*pptr)->next;
      freeVertex(temp);
    }
  }
  free(gptr->vertices);
  free(gptr);
}


void testGraph(HGraph g) {
  Graph *gptr = (Graph*)g;
  printf("count:%d\n", gptr->vertices[0]->name);
  printf("count:%d\n", gptr->vertices[1]->name);
}
