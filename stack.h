#ifndef QUEUE_H
#define QUEUE_H

typedef struct stackRep *Stack;

Stack makeStack();
void freeStack(Stack s);

void pushStack(Stack s, int data);
int popStack(Stack s);

int topStack(Stack s);
int isEmptyStack(Stack s);
int itemsInStack(Stack s);
void showStack(Stack s);

#endif