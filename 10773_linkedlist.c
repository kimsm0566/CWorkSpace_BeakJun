
/*#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int key;
    struct NODE *next;
};

void delete_num(struct NODE*);
void plus_num(struct NODE*,int);
int add_num(struct NODE*);

int main(){

    struct NODE *head, *node;

    head = (struct NODE*)malloc(sizeof(struct NODE));
    node = (struct NODE*)malloc(sizeof(struct NODE));
    
    head->key=0;
    head->next = node;
    node->key = 0;
    node->next = NULL;

    int n;
    int number;
    
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        scanf("%d",&number);
        if (number == 0) delete_num(head);
        else plus_num(head, number);
    }
    printf("%d\n",add_num(head));
}

void delete_num(struct NODE* head){
    struct NODE *ptr;

    ptr = head->next;
    ptr = ptr->next;
    head->next = ptr;
    
}
void plus_num(struct NODE* head,int n){
    struct NODE *ptr;
    struct NODE *insert_ptr = (struct NODE*)malloc(sizeof(struct NODE));
    ptr = head->next; //head 다음 노드로 이동
    head->next = insert_ptr; //insert_ptr을 head와 연결
    insert_ptr->next = ptr; //insert_ptr을 ptr과 연결
    
    insert_ptr->key = n;

}
int add_num(struct NODE* head){
    struct NODE *ptr;
    int cnt=0;
    ptr = head;
    while(ptr){
        cnt = cnt + ptr->key;
        ptr = ptr->next;
    }
    return cnt;
}
*/

#include <stdio.h>
#include <stdlib.h>

struct NODE {
   struct NODE* next;
   int key;
};

struct NODE* MakeNode();
int InsertKey(struct NODE** head, int key);
int DeleteKey(struct NODE** head);
int SumKey(struct NODE* head);

int main(void)
{
   int val;
   int num;
   struct NODE* node = MakeNode();

   scanf("%d", &val);

   for (int i = 0; i < val; i++) {
      scanf("%d", &num);
      if (num != 0) {
         InsertKey(&node, num);
      }
      else {
         DeleteKey(&node);
      }
   }
   printf("%d", SumKey(node));

   return 0;
}

struct NODE* MakeNode() {
   struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
   if (new_node == NULL) {
      printf("ERROR");
      return NULL;
   }
   new_node->next = NULL;
   new_node->key = 0;

   return new_node;
}

int InsertKey(struct NODE** head, int key) {
   struct NODE* newnode = MakeNode();

   newnode->next = *head;
   newnode->key = key;
   *head = newnode;

   return 0;
}

int DeleteKey(struct NODE** head) {
   struct NODE* temp = *head;
   *head = temp->next;
   free(temp);

   return 0;
}

int SumKey(struct NODE* head) {
   struct NODE* ptr = head;
   int sum = 0;

   while (ptr) {
      sum += ptr->key;
      ptr = ptr->next;
   }

   return sum;
}