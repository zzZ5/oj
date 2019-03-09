//最长公共子序列 (Longest common subsequence)
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// const int MAXN = 101;
// char A[MAXN], B[MAXN];
// int dp[MAXN][MAXN];

// int main() {
//     int n;
//     gets(A + 1); //从下标1开始读取
//     gets(B + 1);
//     int lenA = strlen(A + 1);
//     int lenB = strlen(B + 1);

//     for(int i = 0; i < lenA; i++) {
//         dp[i][0] = 0;
//     }
//     for(int i = 0; i < lenB; i++) {
//         dp[0][i] = 0;
//     }

//     for(int i = 1; i <= lenA; i++) {
//         for(int j = 1; j <= lenB; j++) {
//             if(A[i] == B[j]) {
//                 dp[i][j] = dp[i-1][j-1] +1;
//             } else {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }
//     printf("%d\n", dp[lenA][lenB]);
//     return 0;
// }

//hash表查找最长公共子序列
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const LL P = 10000019;
const LL MAXN = 1001;

LL powP[MAXN], H1[MAXN] = {0}, H2[MAXN] = {0};
vector<pair<int, int> > pr1, pr2;

void init(int len) {
    powP[0] = 1;
    for(int i = 1; i < len; i++) {
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

void calSubH(LL H[], int len, vector<pair<int, int> > &pr) {
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            int hashValue = calSingleSubH(H, i , j);
            pr.push_back(make_pair(hashValue, j - i +1));
        }
    }
}

int getMax() {
    int ans = 0;
    for(int i = 0; i < pr1.size(); i++) {
        for(int j = 0; j < pr2.size(); j++) {
            if(pr1[i].first == pr2[j].first) {
                ans = max(ans, pr1[i].second);
            }
        }
    }
    return ans;
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    init(max(str1.length(), str2.length()));
    calH(H1, str1);
    calH(H2, str2);
    calSubH(H1, str1.length(), pr1);
    calSubH(H2, str2.length(), pr2);
    printf("%d\n", getMax());
    return 0;
}
