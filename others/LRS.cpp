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
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const LL P = 10000019;
const LL MAXN = 10001;
LL powP[MAXN], H1[MAXN], H2[MAXN];

void init() {
    powP[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        powP[i] = (powP[i - 1] * P) % MOD;
    }
}

void calH(LL H[], string &str) {
    H[0] = str[0];
    for(int i = 0; i < str.length(); i++) {
        H[i] = (H[i - 1] * P + str[i]) % MOD;
    }
}

int calSingleSubH(LL H[], int i, int j) {
    if(i == 0) {
        return H[j];   
    } else {
        return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
    }
}

int binarySearch(int l, int r, int len, int i, int isEven) {
    while(l < r) {
        int mid = (l + r) / 2;
        int H1L = i - mid + isEven, H1R = i;
        int H2L = len - 1 - (i + mid), H2R = len - 1 - (i + isEven);
        int hashL = calSingleSubH(H1, H1L, H1R);
        int hashR = calSingleSubH(H2, H2L, H2R);
        if(hashL != hashR) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l - 1;
}

int main() {
    init();
    string str;
    getline(cin, str);
    calH(H1, str);
    reverse(str.begin(), str.end());
    calH(H2, str);
    int ans = 0;

    for(int i = 0; i < str.length(); i++) {
        int maxLen = min(i, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 0);
        ans = max(ans, k * 2 + 1);
    }

    for(int i = 0; i < str.length(); i++) {
        int maxLen = min(i + 1, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 1);
        ans = max(ans, k * 2);
    }

    printf("%d", ans);
    return 0;
}
