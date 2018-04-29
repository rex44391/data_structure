#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* HStack;

HStack *getStack(void);
void pushStack(HStack *s, const int data);
int isStackEmpty(HStack *s);
int popStack(HStack *s);
void delStack(HStack *s);

#ifdef __cplusplus
}
#endif

#endif
