#include <cstdio>
#include <math.h>
typedef long long LL;

int main() {
    LL n;
    scanf("%lld", &n);
    LL sqr = (LL)sqrt(n * 1.0), first = 0, len = 0;
    for(LL i = 2; i <= sqr; i++) {
        LL temp = 1, j = i;
        while(1) {
            temp *= j;
            if(n % temp != 0) break;
            if(j - i + 1 > len) {
                first = i;
                len = j - i + 1;
            }
            j++;
        }
    }
    if(len == 0) {
        printf("1\n%lld", n);
    } else {
        printf("%lld\n", len);
        for(LL i = 0; i < len; i++) {
            printf("%lld", first + i);
            if(i < len - 1) printf("*");
        }
    }
    return 0;
}