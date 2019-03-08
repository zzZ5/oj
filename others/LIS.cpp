//最长不下降子序列（可以不连续）
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100;

int A[MAXN], dp[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(A[i] >= A[j] && dp[j] + 1 > dp[i]) {
                dp[i]++;
            }
        }
    }
    int longest = 1;
    for(int i = 0; i < n; i++) {
        if(dp[i] >longest){
            longest = dp[i];
        }
    }
    printf("%d", longest);
    return 0;
}
