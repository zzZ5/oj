#include <cstdio>
const int MAX = 10;
int num[MAX];
int n=1;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int x = a+b;
    if(x == 0) {
        printf("%d",0);
    }
    if(x < 0) {
        printf("-");
        x = -x;
    }
    while(x != 0){
        num[n++] = x%10;
        x = x/10;
    }
    for(int i = n-1; i > 0; i--) {
        if(i%3 == 0 && i != n-1) {
            printf(",%d", num[i]);
        } else{
             printf("%d", num[i]);  
        }
    }
    return 0;
}