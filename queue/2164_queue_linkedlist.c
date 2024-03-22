#include <stdio.h>
#include <stdlib.h>

#define MAXBUF 1000000

struct NODE{
    int key;
    struct NODE* next_node;
};

struct QUEUE{
    struct NODE* front;
    struct NODE* rear;
};

void Make_LastNode(struct QUEUE*,int );
int deleteFirstNode(struct QUEUE* );

int main(){


    int n;
    scanf("%d",&n);

    struct QUEUE * queue = (struct QUEUE*)malloc(sizeof(struct QUEUE));
    struct NODE * head = (struct NODE*)malloc(sizeof(struct NODE));


    queue->front = head;
    queue->rear = head;

    head->key = 0;
    head->next_node = NULL;

    for (int i=0;i<n;i++){
        Make_LastNode(queue,i+1);
    }
    
    head = head->next_node;
    queue->front = queue->front->next_node;


    while(queue->front->key != queue->rear->key){

        int fir = deleteFirstNode(queue);
        
        if(queue->front->key == queue->rear->key) break;

        fir = deleteFirstNode(queue);
        Make_LastNode(queue,fir);

    }
    printf("%d\n",queue->front->key);

}

void Make_LastNode(struct QUEUE* queue,int n){

    struct NODE * newNode = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE * ptr;

    newNode->key = n;
    newNode->next_node = NULL;

    queue->rear->next_node = newNode;
    queue->rear = newNode;

}

int deleteFirstNode(struct QUEUE* queue){

    int front_key = queue->front->key;

    queue->front = queue->front->next_node;
    return front_key;
}