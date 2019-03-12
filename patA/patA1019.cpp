#include <cstdio>

int main() {
    int n, p, x[101];
    scanf("%d %d", &n ,&p);
    int k = 0;
    do {
        x[k++] = n % p;
        n = n / p;
    }while(n != 0);
    bool flag = true;
    for(int i = 0; i < k / 2; i++) {
        if(x[i] != x[k-i-1]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for(int i = 0; i < k; i++) {
        printf("%d", x[k-i-1]);
        if(i < k-1) {
            printf(" ");
        }
    }
    return 0;
}