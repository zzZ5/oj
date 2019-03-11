#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100001;

int d[MAXN], A[MAXN];

int main() {
    int n, query, sum = 0;
    scanf("%d", &n);
    d[0] = 0;
    A[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &A[i+1]);
        sum += A[i+1];
        d[i+1] = sum;
    }
    scanf("%d", &query);
    for(int i = 0; i < query; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(b < a){
            swap(a, b);
        }
        int temp = d[b] - d[a];
        printf("%d\n", min(temp, sum - temp));
    }
    return 0;
}