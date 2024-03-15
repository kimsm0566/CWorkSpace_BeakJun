#include <stdio.h>

#define MAXBUF 1000001

struct QUEUE{
    int top;
    int bottom;
    int key[MAXBUF];
};

int main(){

    int n;
    scanf("%d",&n);
    struct QUEUE queue = {n,0,0};

    for (int i=0;i<n;i++){
        queue.key[i] = i+1;
    }
    for (int i=0;queue.bottom != queue.top-1;i++){
        
        queue.key[queue.bottom++] = 0; //맨 위에 있는 카드 버리기
        queue.key[queue.top++] = queue.key[queue.bottom]; //그 다음카드 맨 뒤로 보내기
        queue.key[queue.bottom++] = 0; //맨 뒤로 보낸카드 지우기
    }
    printf("%d\n",queue.key[queue.bottom]);
}