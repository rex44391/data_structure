#ifndef Queue_H
#define Queue_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* HQueue;
HQueue getQueue(void);
void enQueue(HQueue q, int data); 
int isQueueEmpty(HQueue q); 
int deQueue(HQueue q);
void deleteQueue(HQueue q);

#ifdef __cplusplus
}
#endif

#endif
