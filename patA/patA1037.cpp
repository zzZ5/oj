#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
int coupon[MAXN], product[MAXN];

int main () {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &coupon[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &product[i]);
    }
    sort(coupon, coupon + n);
    sort(product, product + m);
    long long ans = 0;
    int i = 0, j;
    while(i < n && i < m && coupon[i] < 0 && product[i] < 0) {
        ans += coupon[i] * product[i];
        i++;
    }
    i = n - 1;
    j = m -1;
    while(i >= 0 && j >= 0 && coupon[i] >0 && product[j] >0){
        ans += coupon[i] * product[j];
        i--, j--;
    }
    printf("%lld\n", ans);
    return 0;
}