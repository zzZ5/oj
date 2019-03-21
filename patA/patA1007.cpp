// #include <cstdio>
// #include <algorithm>
// using namespace std;
// const  int MAXN = 10001;

// int A[MAXN], dp[MAXN];

// int main() {
//     int n, maxSum;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++) {
//         scanf("%d", &A[i]);
//     }

//     dp[0] = A[0];
//     for(int i = 1; i < n; i++) {
//         dp[i] = max(dp[i-1] +A[i], A[i]);
//     }
//     maxSum = dp[0];
//     int indexR;
//     for(int i = 1; i < n; i++) {
//         if(dp[i] > maxSum) {
//             maxSum = dp[i];
//             indexR = i;
//         }
//     }

//     dp[n-1] = A[n-1];
//     for(int i = n - 2; i > -1; i--) {
//         dp[i] = max(dp[i+1] +A[i], A[i]);
//     }
//     int indexL;
//     for(int i = n-1; i > -1; i--) {
//         if(dp[i] >= maxSum) {
//             maxSum = dp[i];
//             indexL = i;
//         }
//     }

//     if(maxSum < 0) {
//         printf("%d %d %d", 0, A[0], A[n - 1]);
//     } else {
//         printf("%d %d %d", maxSum, A[indexL], A[indexR]);
//     }
//     return 0;
// }

#include <cstdio>
const  int MAXN = 10001;

int A[MAXN];

int main() {
    int n, maxSum, sum, st, ed, tempSt;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    maxSum = -1;
    sum = 0;
    st = 0;
    ed = n-1;
    tempSt = 0;
    for(int i = 0; i < n; i++) {
        sum += A[i];
        if(sum > maxSum){
            maxSum = sum;
            ed = i;
            st = tempSt;
        }
        if (sum < 0) {
            sum = 0;
            tempSt = i + 1;
        }
        
    }
    if(maxSum < 0) {
        printf("%d %d %d", 0, A[0], A[n - 1]);
    } else {
        printf("%d %d %d", maxSum, A[st], A[ed]);
    }
    return 0;
}