#define MAX 9999

#include <stdio.h>
#include "stack.h"

int main(void){

    char string[MAX] = {'\0'};
    char c = '\0';
    int count = 0;
    int trigger = 0;
    Stack s = makeStack();

    printf("Enter line:\n");
    if(fgets(string, MAX, stdin) != NULL){
        while(c != EOF && count < MAX){
            c = string[count];
            if(c == '('){
                pushStack(s, '(');
            } else if(c == '['){
                pushStack(s, '[');
            } else if(c == '{'){
                pushStack(s, '{');
            } else if(c == ')'){
                if(topStack(s) == '('){
                    popStack(s);
                } else {
                    trigger = 1;
                    break;
                }
            } else if(c == ']'){
                if(topStack(s) == '['){
                    popStack(s);
                } else {
                    trigger = 1;
                    break;
                }
            } else if(c == '}'){
                if(topStack(s) == '{'){
                    popStack(s);
                } else {
                    trigger = 1;
                    break;
                }
            }
            count++;
        }
        if(trigger == 1){
            for(int i = 0; i < count; i++){
                printf(" ");
            }
            printf("^");
            printf(" bracket does not match here\n");
        }
        if(!isEmptyStack(s) && trigger == 0){
            trigger = 1;
            printf("missing brackets at the end of string. need:");
            while(!isEmptyStack(s)){
                if(topStack(s) == '('){
                    printf(" )");
                } else if(topStack(s) == '['){
                    printf(" ]");
                } else if(topStack(s) == '{'){
                    printf(" }");
                }
                popStack(s);
            }
            printf("\n");
        }
        if(trigger == 0){
            printf("brackets are matched\n");
        }
    }

    freeStack(s);
    return 0;
}