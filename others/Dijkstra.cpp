#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int INF = 0x3fffffff;

// //邻接表版
// struct Edge {//node为目标顶点,weight为边的权重
//     int node, weight;
// };
// vector<Edge> adj[MAX];
// int n, d[MAX];
// bool visit[MAX] = {false};

// void Dijkstra(int s) {
//     fill(d, d + MAX, INF);
//     d[s] = 0;
//     for(int i = 0; i < n; i++) {
//         int u = -1, minLength = INF;
//         for(int j = 0; j < n; j++) {
//             if(!visit[j] && d[j] < minLength) {
//                 u = j;
//                 d[j] = minLength;
//             }
//         }
//         if(u == -1) {
//             return;
//         }
//         visit[u] = true;
//         for(int v = 0; v < adj[u].size(); v++) {
//             int node = adj[u][v].node;
//             if(!visit[node] && d[u] + adj[u][v].weight < d[v]) {
//                 d[node] = d[u] + adj[u][v].weight;
//             }
//         }
//     }
// }

// //邻接矩阵版
// int n, G[MAX][MAX], d[MAX];
// bool visit[MAX] = {false};

// void Dijkstra(int s) {
//     fill(d, d + MAX, INF);
//     d[s] = 0;
//     for(int i = 0; i < n; i++) {
//         int u = -1, minLength = INF;
//         for(int j = 0; j < n; j++) {
//             if(!visit[j] && d[j] < minLength) {
//                 u = j;
//                 minLength = d[j];
//             }
//         }
//         if(u == -1) {
//             return;
//         }
//         visit[u] = true;
//         for(int v = 0; v < n; v++) {
//             if(!visit[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
//                 d[v] = d[u] + G[u][v];
//             }
//         }
//     }
// }

int main() {

    return 0;
}