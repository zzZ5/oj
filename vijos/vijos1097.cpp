#include<cstdio>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main() {
    int n,temp,a,b,ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        q.push(temp);
    }
    while(q.size() > 1) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a + b);
        ans += a + b;
    }
    printf("%d\n", ans);
    return 0;
}