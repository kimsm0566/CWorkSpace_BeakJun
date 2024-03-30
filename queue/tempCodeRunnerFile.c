#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXBUF 10000

struct QUEUE{
    int floor;
    int key[MAXBUF];
    int rear;
};

// push X: 정수 X를 큐에 넣는 연산이다.
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 큐에 들어있는 정수의 개수를 출력한다.
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

void push(struct QUEUE * ,int);
void pop(struct QUEUE*);
void size(struct QUEUE*);
int empty(struct QUEUE*);
void front(struct QUEUE*);
void back(struct QUEUE*);

int main(void){

    
    int n;
    char command[10] = {'\0'};
    struct QUEUE queue;

    queue.floor = -1;
    queue.rear = -1;


    scanf("%d",&n);


    for (int i=0;i< n;i++){
        scanf("%s",command);
        if (strcmp(command,"push")==0) {
            int number;
            scanf("%d",&number);
            push(&queue,number);
        }
        else if (strcmp(command,"pop")==0) {
            pop(&queue);
        }
        else if (strcmp(command,"size")==0){
            size(&queue);
        }
        else if (strcmp(command,"empty")==0){
            printf("%d\n",empty(&queue));
        }
        else if (strcmp(command,"front")==0){
            front(&queue);
        }
        else if (strcmp(command,"back")==0){
            back(&queue);
        }
    }
    return 0;
}

// push X: 정수 X를 큐에 넣는 연산이다.
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 큐에 들어있는 정수의 개수를 출력한다.
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

void push(struct QUEUE * queue,int n){

    queue->rear++;
    queue->key[queue->rear] = n;
}
void pop(struct QUEUE* queue){

    if (empty(queue) == 1){
        printf("-1\n");
    }

    queue->key[queue->floor] = 0;
    queue->floor++;
}
void size(struct QUEUE* queue){
    if (empty(queue) == 1) {
        printf("0\n");
    }
    else printf("%d\n",queue->rear - queue->floor);

}
int empty(struct QUEUE* queue){

    if (queue->floor > queue->rear) return 1;
    else return 0;

}
void front(struct QUEUE* queue){
    if (empty(queue) == 1) {
        printf("-1\n");
    }

    else if (queue->floor == -1){
        printf("%d\n",queue->key[queue->floor+1]);
    }
    else {
        printf("%d\n",queue->key[queue->floor]);
    }
    
}
void back(struct QUEUE* queue){
    if (empty(queue) == 1) {
        printf("-1\n");
    }
    else printf("%d\n",queue->key[queue->rear]);

}