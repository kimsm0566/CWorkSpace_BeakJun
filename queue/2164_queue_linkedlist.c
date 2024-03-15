//이중연결리스트로 작성해야할듯

#include <stdio.h>
#include <stdlib.h>

#define MAXBUF 1000000

struct NODE{
    int key;
    struct NODE* next;
};

void Make_LastNode(struct NODE ** head,int n);
void deleteFirstNode(struct NODE ** head);
void lastTofirst(struct NODE **head);

int main(){

    int n;

    scanf("%d",&n);

    struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
    node->key=0;
    node->next=NULL;

    for (int i=0;i<n;i++){
        Make_LastNode(&node,i+1);
    }
    node = node->next; //맨 앞의 빈 노드 지우기

    // for (int i=0;node->next != NULL;i++){
    //     deleteFirstNode(&node);
    //     lastTofirst(&node);
    // }
    while(node->next){
        deleteFirstNode(&node);
        lastTofirst(&node); 
    }

    printf("%d\n",node->key);

}

void Make_LastNode(struct NODE **head,int n){//맨 마지막 노드 만들고 값넣기

    struct NODE * ptr = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE * trv;
    trv = *head;
    ptr->key = n;
    ptr->next = NULL;

    while(trv->next){
        trv = trv->next;
    }
    trv->next = ptr;
}

void deleteFirstNode(struct NODE ** head){ //맨 앞의 노드 지우기
    struct NODE *ptr = *head;
    struct NODE *next_ptr = *head;
    next_ptr = next_ptr->next;
    ptr->key=0;
    ptr->next = NULL;
    *head = next_ptr;
}

void lastTofirst(struct NODE **head){ //맨 앞의 값 뒤으로 옮기고 앞 노드 지우기
    struct NODE *ptr = *head;

    Make_LastNode(head,ptr->key);
    deleteFirstNode(head);
}

// #include <stdio.h>
// #include <stdlib.h>

// #define MAXBUF 1000000

// struct NODE{
//     int key;
//     struct NODE* next;
// };

// void Make_FirstNode(struct NODE ** head);
// void deleteNode(struct NODE ** head);
// void lastTofirst(struct NODE **head);

// int main(){

//     int n;

//     scanf("%d",&n);

//     struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
//     node->key=0;
//     node->next=NULL;

//     for (int i=0;i<n;i++){
//         node->key = i+1;
//         if (i+1 != n) Make_FirstNode(&node);
//     }


//     for (int i=0;node->next != NULL;i++){
//         deleteNode(&node);
//         lastTofirst(&node);

//     }

//     printf("%d\n",node->key);

// }

// void Make_FirstNode(struct NODE **head){

//     struct NODE *ptr = (struct NODE*)malloc(sizeof(struct NODE));
//     ptr->key=0;
//     ptr->next = *head;
//     *head = ptr;
// }

// void deleteNode(struct NODE ** head){ //맨 뒤의 노드 지우기
//     struct NODE *ptr = *head;
//     struct NODE *prv_ptr = *head;

//     ptr = ptr->next;

//     while(ptr->next){
//         prv_ptr = prv_ptr->next;

//         ptr=ptr->next;

//     }
//     prv_ptr->next = NULL;
//     free(ptr);
// }

// void lastTofirst(struct NODE **head){
//     struct NODE *ptr = *head;
    
//     while(ptr->next){
//         ptr=ptr->next;
//     }
//     Make_FirstNode(head);
//     struct NODE *first_ptr = *head;

//     first_ptr->key = ptr->key;
//     deleteNode(head);

// }