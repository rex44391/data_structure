#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "stack.h"

typedef struct ele {
  int data;
  struct ele *prev;
} Ele;

Ele *getEle(int data) {
  Ele *e = malloc(sizeof(Ele));
  e->data = data;
  e->prev = NULL;
  return e;
}

void delEle(Ele *e) {
  free(e);
}


typedef struct stack {
  Ele *top;
} Stack;

HStack *getStack() {
  Stack *s = malloc(sizeof(Stack));
  s->top = NULL;
  return ((void*)s);
}

void pushStack(HStack *s, const int data) {
  if(!s) {
    printf("Please input a legit pointer\n");
    return;
  }
  Stack *sptr = (Stack*)s;
  Ele *e = getEle(data);
  e->prev = sptr->top;
  sptr->top = e;
  return;
}

int isStackEmpty(HStack *s) {
  if(!s) {
    printf("Please input a legit pointer\n");
    return -1;
  }
  Stack *sptr = (Stack*)s;
  if(sptr->top) {
    return 0;
  } else {
    return 1;
  }
}

int popStack(HStack *s) {
  if(!s) {
    printf("Please input a legit pointer\n");
    return -1;
  }
  Stack *sptr = (Stack*)s;
  int value;
  if(sptr->top) {
    value = sptr->top->data;
    
    Ele *temp = sptr->top;
    sptr->top = sptr->top->prev;
    delEle(temp);
  } else {
    value =  -1;
  }
  return value;
}

void delStack(HStack *s) {
  if(!s) {
    printf("Please input a legit pointer\n");
    return;
  }
  Stack *sptr = (Stack*)s;
  while(sptr->top) {
    popStack(s);
  }
  free(sptr);
}

void testPrint(HStack *s) {
  Stack *sptr = (Stack*)s;
  Ele *e = sptr->top;
  printf("<<<stack content>>>\n");
  while(e) {
    printf("%d, ", e->data);
    e = e->prev;
  }
  printf("\n<<<end of stack content>>>\n");
}



/*int main() {
  HStack *s = getStack();
  pushStack(s, 1);
  pushStack(s, 9);
  pushStack(s, 7);
  pushStack(s, 11);
  pushStack(s, 8);
  testPrint(s);
  popStack(s);
  popStack(s);
  popStack(s);
  popStack(s);
  popStack(s);
  popStack(s);
  popStack(s);
  testPrint(s);
  pushStack(s, 4);
  pushStack(s, 6);
  pushStack(s, 5);
  testPrint(s);
  delStack(s);
  s = NULL;
  pushStack(s, 1);
  return 0;
}*/
