#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct stackNode {
    int data;
    struct stackNode *next;
} stackNode;

struct stackRep{
    int size;
    stackNode *top;
};

static stackNode *makeStackNode(int data){
    stackNode *new;
    new = malloc(sizeof(struct stackNode));
    assert(new != NULL);
    new->data = data;
    new->next = NULL;
    return new;
}

Stack makeStack(){
    Stack new;
    new = malloc(sizeof(struct stackRep));
    assert(new != NULL);
    new->size = 0;
    new->top = NULL;
    return new;
}

void freeStack(Stack s){
    assert(s != NULL);
    stackNode *iter = s->top;
    stackNode *temp = s->top;
    if(temp == NULL){
        free(s);
        return;
    }
    do{
        iter = temp;
        temp = iter->next;
        free(iter);
    } while (temp != NULL);
    free(s);
}

void pushStack(Stack s, int data){
    assert(s != NULL);
    stackNode *node = makeStackNode(data);
    node->next = s->top;
    s->top = node;
    s->size += 1;
}
int popStack(Stack s){
    assert(s != NULL);
    stackNode *temp = s->top;
    if(temp != NULL){
        temp = temp->next;
        free(s->top);
        s->top = temp;
        s->size -= 1;
    } else {
        return 1;
    }
    return 0;
}

int topStack(Stack s){
    assert(s != NULL);
    if(s->top == NULL){
        return EOF;
    }
    return s->top->data;
}

int isEmptyStack(Stack s){
    assert(s != NULL);
    if(s->size == 0){
        return 1;
    }
    return 0;
}
int itemsInStack(Stack s){
    assert(s != NULL);
    return s->size;
}
void showStack(Stack s){
    assert(s != NULL);
    stackNode *node = s->top;
    printf("[");
    while(node != NULL){
        printf("%d", node->data);
        printf("] -> [");
        node = node->next;
    }
    printf("X]\n");
}
