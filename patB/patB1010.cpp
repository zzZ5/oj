#include <cstdio>
const int MXAN = 1001;
int a[MXAN] = {0};

int main() {
    int k, e;
    while(scanf("%d%d", &k, &e) != EOF) {
        a[e] = k;
    }
    a[0] = 0;
    int count = 0;
    for(int i = 1; i < MXAN; i++) {
        if(a[i] != 0){
            a[i - 1] = a[i] * i;
            a[i] = 0;
            count++;
        }
    }
    if(count == 0) {
        printf("0 0");
    } else {
        for(int i = MXAN - 1; i >= 0; i--) {
            if(a[i] != 0) {
                printf("%d %d", a[i], i);
                count--;
                if(count > 0) {
                    printf(" ");
                }
                
            }
        }
    }
    return 0;
}