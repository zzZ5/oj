#include <cstdio>
#include <set>
using namespace std;
const int N = 51;
set<int> st[N];

void compare(int a, int b) {
    int total = st[b].size();
    int same = 0;
    for(set<int>::iterator it = st[a].begin(); it != st[a].end(); it++) {
        if(st[b].find(*it) != st[b].end()) same++;
        else total++;
    }
    //这个方法会超时
    // int total = st[a].size() + st[b].size();
    // set<int> sum;
    // sum.insert(st[a].begin(), st[a].end());
    // sum.insert(st[b].begin(), st[b].end());
    // int same = total - sum.size();
    // total = total - same;
    printf("%.1f%%\n", same * 100.0 / total);
}

int main() {
    int n, k, q, v, st1, st2;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &v);
            st[i].insert(v);
        }
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d %d", &st1, &st2);
        compare(st1, st2);
    }
    return 0;
}