#include <cstdio>

int fuc(int x) {
    int index = 1;
    while(x > 1) {
        x -= index;
        index++;
    }
    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    int x, ans;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        ans = fuc(x) == 1 ? 1: 0;
        printf("%d\n", ans);
    }
    return 0;
}