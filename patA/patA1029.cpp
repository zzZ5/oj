#include <cstdio>
#include <queue>
using namespace std;
const int INF = 0x7fffffff;
int main() {
    queue<int> a, b;
    long long tnum;
    int n, m, num, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &tnum);
        num = min((long long)INF, tnum);
        a.push(num);
    }
    a.push(INF);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%lld", &tnum);
        int num = min((long long)INF, tnum);
        b.push(num);
        if(cnt == (n + m - 1) / 2) {
            printf("%d", min(a.front(), b.front()));
            return 0;
        }
        if(a.front() < b.front()) //一边读取, 一边pop, 减少内存占用
            a.pop();
        else
            b.pop();
        cnt++;
    }
    b.push(INF);
    for(; cnt < (n + m - 1) / 2; cnt++) {
        if(a.front() < b.front())    
            a.pop();
        else                         
            b.pop();
    }
    printf("%d", min(a.front(), b.front()));
    return 0;
}