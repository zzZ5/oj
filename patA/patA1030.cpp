#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 501;
const int INF = 0x3fffffff;
int nodeNum, edgeNum, st, ed, G[MAX][MAX], cost[MAX][MAX];
int consume[MAX], d[MAX], pre[MAX];
bool visit[MAX]={false};

void Dijkstra() {
    fill(d, d + MAX, INF);
    fill(consume, consume + MAX, INF);
    d[st] = 0;
    consume[st] = 0;
    for(int i = 0; i < nodeNum; i++) {
        int u = -1, minLength = INF;
        for(int j = 0; j < nodeNum; j++) {
            if(!visit[j] && d[j] < minLength) {
                u = j;
                minLength = d[j];
            }
        }
        if(u == -1) {
            return;
        }
        visit[u] = true;
        for(int v = 0; v < nodeNum; v++) {
            if(!visit[v] && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    consume[v] = consume[u] + cost[u][v];
                    pre[v] = u;
                } else if(d[u] + G[u][v] == d[v]) {
                    if(consume[u] + cost[u][v] < consume[v]){
                        consume[v] = consume[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int node){
    if(node == st){
        printf("%d ", node);
        return;
    }
    DFS(pre[node]);
    printf("%d ", node);
}

int main() {
    scanf("%d%d%d%d", &nodeNum, &edgeNum, &st, &ed);
    fill(G[0], G[0] + MAX*MAX, INF);
    int u,v;
    for(int i = 0; i < edgeNum; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra();
    DFS(ed);
    printf("%d %d\n", d[ed], consume[ed]);
    return 0;
}