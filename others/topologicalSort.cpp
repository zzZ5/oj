#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXV = 101;

vector<int> G[MAXV];
int nodeNum, edgeNum, inDegree[MAXV];

bool topologicalSort() {
    int num = 0;
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
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
        G[u].clear();
        num++;
    }
    return num == nodeNum;
}


int main() {
    int u, v;
    fill(inDegree, inDegree + MAXV, 0);
    scanf("%d%d", &nodeNum, &edgeNum);
    for(int i = 0; i < edgeNum; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        inDegree[v]++;
    }
    topologicalSort();
    return 0;
}