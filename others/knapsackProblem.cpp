//背包问题
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 101;
const int MAXV = 10001;

int w[MAXN], c[MAXN], dp[MAXV];

int main() {
    int n, V;
    scanf("%d%d", &n, &V);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for(int v = 0; v <= V; v++) {
        dp[v] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int v = V; v >= w[i]; v--) {
            dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= V; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
        }
    }
    printf("%d", ans);
    return 0;
}