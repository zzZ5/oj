//最长公共子序列 (Longest common subsequence)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 101;
char A[MAXN], B[MAXN];
int dp[MAXN][MAXN];

int main() {
    int n;
    gets(A + 1); //从下标1开始读取
    gets(B + 1);
    int lenA = strlen(A + 1);
    int lenB = strlen(B + 1);

    for(int i = 0; i < lenA; i++) {
        dp[i][0] = 0;
    }
    for(int i = 0; i < lenB; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= lenA; i++) {
        for(int j = 1; j <= lenB; j++) {
            if(A[i] == B[j]) {
                dp[i][j] = dp[i-1][j-1] +1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d\n", dp[lenA][lenB]);
    return 0;
}