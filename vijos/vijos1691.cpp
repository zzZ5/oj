#include <cstdio>
#include <algorithm>
using namespace std;

int a[10001];

int main() {
    int n, x, y, mid, sum;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        a[i] = y;
    }
    sort(a, a + n);
    mid = a[n/2];
    for(int i = 0; i < n; i++)
        sum += abs(a[i] - mid);
    printf("%d\n", sum);
    return 0;
}