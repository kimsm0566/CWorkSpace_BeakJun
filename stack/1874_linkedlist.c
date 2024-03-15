#include <stdio.h>
#include <stdlib.h>

#define MAXBUF 100000

struct NODE{
    int key;
    struct NODE *next;
};

void push(struct NODE **head,int n);
void pop(struct NODE **head);

int main(){

    int n, index=0,num=1;
    int input_numbers;
    char plus_minus[MAXBUF*2] = "";
    struct NODE *list;
    list = (struct NODE*)malloc(sizeof(struct NODE));
  
    list->key =0;
    list->next = NULL;

    scanf("%d",&n);

    for (int i=0;i<n;i++){
        scanf("%d",&input_numbers);
        while(1){
            if (list->key < input_numbers){
                push(&list,num++);
                plus_minus[index++] = '+';
            }
            else break;
        }
        if (list->key == input_numbers){
            pop(&list);
            plus_minus[index++] = '-';
        }    
        else {
            printf("NO\n");
            break;
        }         
    }

    if (index >= n*2){
        for (int i=0;i<index;i++){
            printf("%c\n",plus_minus[i]);
        }
    }
}

void push(struct NODE **head,int n){

    struct NODE * ptr;
    ptr = (struct NODE*)malloc(sizeof(struct NODE));

    ptr->key = n;
    ptr->next = *head;
    *head = ptr;
}
void pop(struct NODE **head){

    struct NODE * ptr;
    ptr = *head;
    *head = ptr->next;
}