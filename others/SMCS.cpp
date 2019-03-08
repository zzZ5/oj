//最大连续子序列和 Sum of maximal continuous subsequences
#include <cstdio>
#include <algorithm>
using namespace std;
const  int MAXN = 10001;

int A[MAXN], dp[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    dp[0] = A[0];
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] +A[i], A[i]);
    }
    int maxSum=dp[0];
    int index;
    for(int i = 1; i < n; i++) {
        if(dp[i] > maxSum) {
            maxSum = dp[i];
            index = i;
        }
    }
    int indexL, indexR = index;
    for(indexL = indexR-1; indexL >= 0; indexL--) {
        if(dp[indexL] == A[indexL]) {
            break;
        }
    }
    printf("%d->%d=%d", indexL, indexR, maxSum);
    return 0;
}