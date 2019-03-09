// lowbit = x & (-x)  即能整除x的最大2的幂次 1, 2, 4, 8等
// 树状数组
#include <cstdio>
#include <cstring>
#define lowbit(i) ((i) & (-i))
const int MAXN = 10001;
int c[MAXN]; 

void update(int x, int v) {
    for(int i = x; i <= MAXN; i += lowbit(i)) {
        c[i] += v;
    }
}

int getSum(int x) {
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

int main() {
    memset(c, 0, sizeof(c));
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        update(x, 1);
        printf("%d\n", getSum(x-1));
    }
    return 0;
}