//深度搜索算法会运行超时
// #include <cstdio>
// const int N = 100001;

// double a[N];
// double ans = 0.0;
// int n;

// void dfs(int k){
//     if(k > n){
//         return;
//     }
//     for(int i = 0; i < n; i++) {
//         if(n - i >= k) {
//             for(int j = i; j < i + k; j++) {
//                 ans += a[j];
//             }
//         }
//     }
//     dfs(k + 1);
// }

// int main() {
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++) {
//         scanf("%lf", &a[i]);
//     }
//     dfs(1);
//     printf("%.2f\n", ans);
//     return 0;
// }

#include <cstdio>

int main() {
    int n;
    double v, ans = 0.0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &v);
        ans += v * i * (n + 1 -i);
    }
    printf("%.2f\n", ans);
    return 0;
}
