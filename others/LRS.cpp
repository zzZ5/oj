//最长回文子串 Longest return substring
// #include<cstdio>
// #include <cstring>
// const int MAXN = 1001;

// char S[MAXN];
// int dp[MAXN][MAXN];

// int main() {
//     gets(S);
//     int len = strlen(S), ans = 1;
//     memset(dp, 0, sizeof(dp));
//     for(int i = 0; i < len; i++) {
//         dp[i][i] = 1;
//         if(i < len -1) {
//             if(S[i] = S[i + 1]) {
//                 dp[i][i+1] = 1;
//                 ans = 2;
//             }
//         }
//     }
//     for(int L = 2; L < len; L++) {
//         for(int i = 0; i + L < len; i++) {
//             int j = i + L;
//             if(S[i] == S[j] && dp[i + 1][j - 1]) {
//                 dp[i][j] = 1;
//                 ans = L + 1;
//             }
//         }
//     }
//     printf("%d\n", ans);
//     return 0;
// }

//hash表查找最长回文子串