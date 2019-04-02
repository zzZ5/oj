#include<cstdio>
#define ll long long
using namespace std;
const int N = 100100;

int n, a[2][N], ans[N << 1], k;
ll m;

int main() {
    int i, j;
    scanf("%d %lld", &n, &m);
    for(i = 1; i <= n; i++) scanf("%d",&a[0][i]), a[0][i]--;
    for(j = 1; (1LL << j) <= m; j++) { // 处理第 2^j 那一次变化
        if(m & (1LL << j)) {
            ll l = (1LL << j);
            for(i = 1; i <= n; i++) {
                int x = (i - (l >> 1) % n + n - 1) % n + 1; // i 左边第 2^(j-1) 个数字 
                int y = (i + (l >> 1) % n + n - 1) % n + 1; // i 左边第 2^(j+1) 个数字 
                a[k ^ 1][i] = a[k][x] ^ a[k][y];
            }
            k ^= 1;
        }
    }
    for(i = 1; i <= n; i++) ans[(i << 1) - 1] = a[k][i]; //先后先放在奇数位 
    if(m & 1) { // 处理 2^0 变化
        for(i = 1; i <= n; i++) ans[i<<1]=ans[i+i-1]^ans[i==n?1:i<<1|1];
        for(i = 1; i <= n; i++) ans[i + i - 1] =- 1;  // 把不需要的奇数位变成 0 
    }
    else for(i = 1; i <= n; i++) ans[i + i] =- 1;  // 把不需要的偶数位变成 0 
    for(i = 1; i <= (n << 1); i++) 
        printf("%d%c", ans[i] + 1, i == (n << 1)? '\n':' '); // 注意还原题意 （ ans+1 ） 
    return 0;
}
// 第2^k行每个数是原序列该位置左侧第2^(k-1)个数和右侧第2^(k-1)个数的异或