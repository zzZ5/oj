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
    vis[v] == true;
    for(int i = 0; i < G[v].size(); i++) {
        dfs(G[v][i]);
    }
}

int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i <m; i++) {
        
    }

    return 0;
}