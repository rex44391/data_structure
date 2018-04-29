#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "queue.h"

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *getNode(int data) {
  Node *n = (Node*)malloc(sizeof(Node));
  n->data = data;
  n->next = NULL;
  return n;
}

void delNode(Node *n) {
  if(!n) {
    printf("Please input a legit pointer!\n");
    return;
  }
  free(n);
}

typedef struct Queue {
  Node *head;
} Queue;

HQueue getQueue() {
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->head = NULL;
  return ((void*)q);
}

void enQueue(HQueue q, int data) {
  if(!q) {
    printf("Please input a legit pointer!\n");
    return;
  }
  Queue *qptr = (Queue*)q;
  Node **tail = &(qptr->head);
  while( (*tail) != NULL) {
    tail = &((*tail)->next);
  }
  (*tail) = getNode(data);
  return;
}

int isQueueEmpty(HQueue q) {
  if(!q) {
    printf("Please input a legit pointer!\n");
    return -1;//abnormal
  }
  Queue *qptr = (Queue*)q;
  if(qptr->head) { 
    return 0;//not empty
  } else {
    return 1;//is empty
  }
}

int deQueue(HQueue q) {
  if(!q) {
    printf("Please input a legit pointer!\n");
    return -1;
  }
  Queue *qptr = (Queue*)q;
  if(!(qptr->head)) { 
      return -1;
  }
  int reValue = qptr->head->data;
  Node *temp = qptr->head;
  qptr->head = qptr->head->next; 
  delNode(temp);
  return reValue;
}

void deleteQueue(HQueue q) {
  //using delete not del
  if(!q) {
    printf("Please input a legit pointer\n");
    return;
  }
  Queue *qptr = (Queue*)q;
  while(qptr->head) {
    deQueue(q);
  }
  free(qptr);
}

void printQueue(HQueue q) {
  if(isQueueEmpty(q))
      return;
  Queue *qptr = (Queue*)q;
  Node *iter = qptr->head;
  printf("Queue: ");
  while(iter) {
    printf("%d, ", iter->data);
    iter = iter->next;
  }
  printf("\n");
}



