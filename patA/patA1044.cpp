#include <cstdio>
const int N = 100001;
const int MAX = 0x3fffffff;
int n, price, nearS=MAX, sum[N];
int binary(int left, int right, int x) {
    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(sum[mid] > x) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    scanf("%d %d", &n, &price);
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        int j = binary(i, n + 1, sum[i - 1] + price);
        if(sum[j - 1] - sum[i - 1] == price) {
            nearS = price;
        } else if(j <= n && sum[j] - sum[i - 1] < nearS) {
            nearS = sum[j] - sum[i - 1];
        }
    }
    for(int i = 1; i <= n; i++) {
        int j = binary(1, n + 1, sum[i - 1] + nearS);
        if(sum[j - 1] - sum[i - 1] == nearS) {
            printf("%d-%d\n", i, j - 1);
        }
    }
    return 0;
}