#include <stdio.h>

#define MAXBUF 1000

struct STACK{
    int buf[MAXBUF];
    int top;
};
struct CHAR_STACK{
    char buf[MAXBUF];
    int top;
};

void push(struct CHAR_STACK*, struct STACK *, struct STACK*);
void pop(struct CHAR_STACK*, struct STACK*, struct STACK*);
void delete_arr(int sky[]);

int main(){

    int n;
    int ground_buf[MAXBUF];

    struct STACK stack;
    struct STACK test;
    struct STACK sky;
    struct CHAR_STACK plus_mainus;
    stack.top = 0;
    test.top = 0;
    sky.top =0;
    plus_mainus.top =0;

    scanf("%d",&n);

    for (int i=1;i<=n;i++){ //버퍼에 순서대로 넣기
        sky.buf[i-1] = i;
        sky.buf[i] = 0;
    }
    

    for (int i=0;i<n;i++){ //목표 수열 입력받기
        scanf("%d",&ground_buf[i]);
        ground_buf[i+1] = 0;
    }
    push(&plus_mainus, &sky, &stack);
    for (int i=0;i<n;i++){//4

        if (ground_buf[i-1] < ground_buf[i]){
            for (int j=0;sky.buf[j-1] != ground_buf[i];j++){
                
                if (stack.buf[stack.top-1] == ground_buf[i]){
                    pop(&plus_mainus, &test,&stack);
                }
                else if(stack.top != 8) {
                    push(&plus_mainus, &sky, &stack);
                }
                else if (stack.top == 8) break;
            }
        }
        else if (ground_buf[i-1] > ground_buf[i]){
            if (stack.buf[stack.top-1] == ground_buf[i]){
                pop(&plus_mainus, &test,&stack);
            }
            else {
                printf("NO\n");
                printf("%d-------------\n",i);
                break;
            }
        }
    }
    for (int i=0; test.buf[i] != '\0';i++){
        printf("%d ",test.buf[i]);
    }
    printf("\n");
    for (int i=0;plus_mainus.buf[i]!='\0';i++){
        printf("%c\n",plus_mainus.buf[i]);
    }
}


void push(struct CHAR_STACK* pn, struct STACK *sky, struct STACK* st){

    st->buf[st->top++] = sky->buf[sky->top++];
    pn->buf[pn->top++] = '+';
    pn->buf[pn->top] = '\0';

}
void pop(struct CHAR_STACK* pn, struct STACK *test, struct STACK* st){
    int i=0;
    
    st->top--;

    test->buf[test->top++] = st->buf[st->top]; //test에 저장
    
    st->buf[st->top] = 0; //숫자 지우기

    pn->buf[pn->top++] = '-'; //+-배열에 저장
    pn->buf[pn->top] = '\0';
    
}
