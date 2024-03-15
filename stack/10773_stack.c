/*
#include <stdio.h>

#define MAXBUF 1000000

struct STACK
{
    int buf[MAXBUF];
    int top;
};

int main(){

    struct STACK stack;
    stack.top=0;
    int add_number=0;
    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        int number;
        scanf("%d",&number);
        if (number==0){
            stack.buf[stack.top-1]=0;
            stack.top--;
        }
        else {
            stack.buf[stack.top] = number;
            stack.top++;
        }
    }
    for (int i=0;i<stack.top;i++){
        add_number+=stack.buf[i];
    }

    printf("%d\n",add_number);
    

}
*/

#include <stdio.h>

int main(void)
{
    int value;
    int arr[100001] = { 0 };
    int num;
    int count = 0, sum = 0;

    scanf("%d", &value);

    for (int i = 0; i < value && count < 100001; i++) {
        scanf("%d", &num);

        if (num == 0 && count > 0) {
            sum -= arr[--count];
        }
        else if (count < 100001) {
            arr[count++] = num;
            sum += num;
        }
    }

    printf("%d", sum);
    return 0;
}
