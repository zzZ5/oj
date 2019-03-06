#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 501;
const int INF = 0x3fffffff;

int d[MAX], w[MAX], num[MAX];
int G[MAX][MAX], weight[MAX], nodeNum, edgeNum, st, ed;
bool visit[MAX] = {false};

void Dijkstra() {
    fill(d, d + MAX, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[st] = 0;
    w[st] = weight[st];
    num[st] = 1;
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
            if(!visit[v] && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                } else if(d[u] + G[u][v] == d[v]) {
                    if(w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}


int main() {
    scanf("%d%d%d%d", &nodeNum, &edgeNum, &st, &ed);
    for(int i = 0; i < nodeNum; i++) {
        scanf("%d", &weight[i]);
    }
    int u, v;
    fill(G[0], G[0]+MAX*MAX, INF);
    for(int i = 0; i < edgeNum; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra();
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}