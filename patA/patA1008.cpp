#include <cstdio>

int main() {
    int n, total = 0;
    int cur = 0, to;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &to);
        if(to > cur) {
            total = total + (to - cur) * 6;
        } else {
            total = total + (cur - to) * 4;            
        }
        total += 5;
        cur = to;
    }
    printf("%d\n", total);
    return 0;
}