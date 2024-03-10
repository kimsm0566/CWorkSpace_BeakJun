/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXBUF 100000

struct STACK
{
    int buf[MAXBUF];
    int top;
};

void push(struct STACK * ,int);
void pop(struct STACK*);
void size(struct STACK*);
int empty(struct STACK*);
void top(struct STACK*);

int main(void){

    struct STACK stack;
    stack.top = 0;
    int n=0;
    char command[10] = {'\0'};
    
    scanf("%d",&n);


    for (int i=0;i<n;i++){
        scanf("%s",command);
        if (strcmp(command,"push")==0) {
            int number;
            scanf("%d",&number);
            push(&stack,number);
        }
        else if (strcmp(command,"pop")==0) {
            pop(&stack);
        }
        else if (strcmp(command,"size")==0){
            size(&stack);
        }
        else if (strcmp(command,"empty")==0){
            printf("%d\n",empty(&stack));
        }
        else if (strcmp(command,"top")==0){
            top(&stack);
        }
    }
}

void push(struct STACK * stack ,int n){

    stack->buf[stack->top] = n;
    stack->top = stack->top + 1;
}
void pop(struct STACK* stack){

    if (empty(stack)) printf("-1\n");
    else {
        printf("%d\n",stack->buf[stack->top-1]);
        stack->buf[stack->top-1] = 0;
        stack->top--;
    }
}
void size(struct STACK* stack){
    printf("%d\n",stack->top);
}
int empty(struct STACK* stack){
    if (stack->top == 0) {
        return 1;
    }
    else{
        return 0;
    }
}
void top(struct STACK* stack){
    if (empty(stack)==1) printf("-1\n");
    else printf("%d\n",stack->buf[stack->top-1]);
}
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 10001
#define MAX_LENGTH 7
#define MAX_ARR 13

int main() {

   int val;
   char arr[MAX_ARR];
   char temp[MAX_LENGTH];
   int stack[MAX_NUM];
   int num = 0;
   scanf("%d", &val);

   for (int i = 0; i < val; i++) {
      scanf("%s", arr);
      //arr[sizeof(arr) - 1] = '\0';
      if (strcmp(arr, "push") == 0) {
         scanf("%s", temp);
         //temp[sizeof(temp) - 1] = '\0';
         stack[num] = atoi(temp);
         num++;
      }
      else if (strcmp(arr, "pop") == 0) {
         if (num == 0) {
            printf("-1\n");
         }
         else {
            num--;
            printf("%d\n", stack[num]);
            stack[num] = 0;
         }
      }
      else if (strcmp(arr, "size") == 0) {
         printf("%d\n", num);
      }
      else if (strcmp(arr, "empty") == 0) {
         if (num == 0) {
            printf("1\n");
         }
         else {
            printf("0\n");
         }
      }
      else if (strcmp(arr, "top") == 0) {
         if (num == 0) {
            printf("-1\n");
         }
         else {
            int tmp = num-1;
            printf("%d\n", stack[tmp]);
         }

      }
   }
   return 0;
}

