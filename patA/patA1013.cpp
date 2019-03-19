#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1001;

vector<int> G[N];
bool visit[N] = {false};
int curPoint;

void dfs(int v) {
    if(v == curPoint) return;
    visit[v] = true;
    for(int i = 0; i < (int)G[v].size(); i++) {
        if(!visit[G[v][i]])
            dfs(G[v][i]);
    }
}

int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i <m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d", &curPoint);
        memset(visit, false, sizeof(visit));
        int block= 0;
        for(int j = 1; j <= n; j++) {
            if(j != curPoint && !visit[j]) {
                dfs(j);
                block++;
            }
        }
        printf("%d\n", block - 1);
    }
    return 0;
}