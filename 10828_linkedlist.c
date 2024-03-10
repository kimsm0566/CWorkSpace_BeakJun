#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NODE
{
    int key;
    struct NODE * next;
};

void push(struct NODE * ,int,int*);
void pop(struct NODE*,int*);
void size(int);
int empty(int);
void top(struct NODE*, int);


int main(){

    struct NODE *node = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE *head = (struct NODE*)malloc(sizeof(struct NODE));
    node = NULL;
    head->key=0;
    head->next = node;

    int n=0;
    int node_top=0;
    char command[10] = {'\0'};
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        scanf("%s",command);
        if (strcmp(command,"push")==0) {
            int number;
            scanf("%d",&number);
            push(head,number,&node_top);
        }
        else if (strcmp(command,"pop")==0) {
            pop(head,&node_top);
        }
        else if (strcmp(command,"size")==0){
            size(node_top);
        }
        else if (strcmp(command,"empty")==0){
            printf("%d\n",empty(node_top));
        }
        else if (strcmp(command,"top")==0){
            top(head, node_top);
        }


    }




}


void push(struct NODE * head,int n,int *node_top){

    struct NODE *insert_node = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE * ptr = head;
    insert_node->key = n;
    while(ptr->next){
        ptr = ptr->next;
    }
    

    ptr->next = NULL;
    insert_node->next = ptr->next;
    ptr->next = insert_node;

    *node_top = *node_top+1;
}
void pop(struct NODE* head, int *node_top){

    if (*node_top == 0) printf("-1\n");
    else{
        struct NODE *ptr =head;
        struct NODE *prv_node;
        for(int i=0;i<*node_top;i++){
            prv_node = ptr;
            ptr = ptr->next;
        }
        printf("%d\n",ptr->key);
        prv_node->next = NULL;
        *node_top = *node_top-1;
    }
}
void size(int node_top){
    printf("%d\n",node_top);
}
int empty(int node_top){
    if (node_top == 0) return 1;
    else return 0;
}
void top(struct NODE* head, int node_top){
    
    if (node_top==0) printf("-1\n");
    else {
        struct NODE *ptr = head;
        while(ptr->next){
            ptr = ptr->next;
        }

        printf("%d\n",ptr->key);
    }
    

}