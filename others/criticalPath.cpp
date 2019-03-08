#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXV = 101;
struct Edge {
    int node, weight;
};

vector<Edge> G[MAXV];
int nodeNum, edgeNum, inDegree[MAXV], ve[MAXV], vl[MAXV];
stack<int> topOrder;



bool topologicalSort() {
    queue<int> q;
    for(int i = 0; i < nodeNum; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        printf("%d", u);
        q.pop();
        topOrder.push(u);
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].node;
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
            if(ve[u] + G[u][i].weight > ve[v]) {
               ve[v] =  ve[u] + G[u][i].weight;
            }
        }
    }
    printf("\n");
    return topOrder.size() == nodeNum;
}

int criticalPath() {
    fill(ve, ve + MAXV, 0);
    if(!topologicalSort()){
        return -1;
    }
    fill(vl, vl + MAXV, ve[nodeNum-1]);
    while(!topOrder.empty()) {
        int u = topOrder.top();
        topOrder.pop();
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].node;
            if(vl[v] - G[u][i].weight < vl[u]) {
                vl[u] = vl[v] - G[u][i].weight;
            }
        }
    }

    for(int u = 0; u < nodeNum; u++) {
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].node, w = G[u][i].weight;
            int e = ve[u], l = vl[v] - w;
            if(e == l) {
                printf("%d->%d\n", u , v);
            }

        }
    }
    return ve[nodeNum-1];
}



int main() {
    int u, v, w;
    fill(inDegree, inDegree + MAXV, 0);
    scanf("%d%d", &nodeNum, &edgeNum);
    for(int i = 0; i < edgeNum; i++) {
        scanf("%d%d%d", &u, &v, &w);
        Edge edge = {
            .node = v,
            .weight = w
        };
        G[u].push_back(edge);
        inDegree[v]++;
    }
    criticalPath();
    return 0;
}