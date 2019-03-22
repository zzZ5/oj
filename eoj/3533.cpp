#include <cstdio>

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int man = 1, woman = 1;
    for(int i = 0; i < k; i++) {
        printf("%d %d\n", man++, woman++);
        if(man > n) man -= n;
        if(woman > m) woman -= m;
    }
    return 0;
}