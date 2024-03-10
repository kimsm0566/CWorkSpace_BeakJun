#include <stdio.h>

#define MAXBUF 1000

struct STACK{
    int buf[MAXBUF];
    int top;
};

void push(int[], struct STACK*,int);
void pop(int[], struct STACK*,int);

int main(){

    int n;
    int buf[MAXBUF];
    int result_buf[MAXBUF];
    int test_buf[MAXBUF]={0};
    char plus_mainus[MAXBUF] = {0};

    scanf("%d",&n);
    struct STACK stack;

    for (int i=1;i<=n;i++){ //버퍼에 순서대로 넣기
        buf[i-1] = i;
    }
    stack.top = 0;
    for (int i=0;i<n;i++){ //목표 수열 입력받기
        scanf("%d",&result_buf[i]);
    }

    for (int i=0;i<n;i++ ){
        if (result_buf[i] < result_buf[i-1]){
            for (int j=0;stack.buf[j]!='\0';j++){
                if (result_buf[i] == stack.buf[j]){
                    pop(test_buf,&stack,i);
                    break;
                }
            }
        }
        
        else{
            for (int j=0;stack.buf[j] != result_buf[i];j++){
                if (stack.buf[j-1] == result_buf[i]) {
                    pop(test_buf,&stack,i);
                    break;
                }
                push(buf,&stack,stack.top+j);
            }
        }
    }
}


void push(int buf[], struct STACK* st,int j){

    st->buf[st->top] = buf[j];
    printf("+\n");
}
void pop(int test[], struct STACK* st,int i){

    st->top--;
    test[i] = st->buf[st->top];
    st->buf[st->top] = 0;
    printf("-\n");


    
}