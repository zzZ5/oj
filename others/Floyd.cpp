#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 0x3fffffff;
const int MAXN = 100;

int nodeNum, edgeNum, dis[MAXN][MAXN];

void Floyd() {
    for(int k = 0; k < nodeNum; k++) {
        for(int i = 0; i < nodeNum; i++) {
            for(int j = 0; j < nodeNum; j++) {
                if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main() {
    int  u, v, w;
    fill(dis[0], dis[0] + MAXN * MAXN, INF);
    scanf("%d%d", &nodeNum, &edgeNum);
    for(int i = 0; i < nodeNum; i++) {
        dis[i][i] = 0;
    }
    for(int i = 0; i < edgeNum; i++) {
        scanf("%d%d%d", &u, &v, &w);
        dis[u][v] = w;
    }
    Floyd();
    for(int i = 0; i < nodeNum; i++) {
        for(int j = 0; j < nodeNum; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
