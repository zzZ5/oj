#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1000;
const int INF = 0x3fffffff;

int nodeNum, edgeNum, G[MAXN][MAXN], d[MAXN];
bool visit[MAXN] = {false};

int Prim() {
    fill(d, d + MAXN, INF);
    d[0] = 0;
    int ans = 0;
    for(int i = 0; i < nodeNum; i++) {
        int u = -1, minLength = INF;
        for(int j = 0; j < nodeNum; j++) {
            if(!visit[j] && d[j] < minLength) {
                u = j;
                minLength = d[j];
            }
        }
        if(u == -1) {
            return -1;
        }
        visit[u] = true;
        ans += d[u];
        for(int v = 0; v < nodeNum; v++) {
            if(!visit[v] && G[u][v]!=INF && G[u][v] < d[v]) {
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

int main() {
    int  u, v, w;
    fill(G[0], G[0] + MAXN * MAXN, INF);
    scanf("%d%d", &nodeNum, &edgeNum);
    for(int i = 0; i < edgeNum; i++) {
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] =  G[v][u] = w;
    }
    int ans = Prim();
    printf("%d\n", ans);
    return 0;
}