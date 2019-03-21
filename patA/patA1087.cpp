#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int MAXV = 201;
const int INF = 0x3fffffff;

int n, m, st, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], numPath = 0, maxW = 0;
double maxAvg = 0;
bool visit[MAXV] = {false};
vector<int> pre[MAXV], tempPath, path;
map<string, int> city2Index;
map<int, string> index2City;

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(!visit[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(!visit[v] && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {
    if(v == st) {
        tempPath.push_back(v);
        numPath++;
        int tempW = 0;
        for(int i = tempPath.size() - 2; i >= 0; i--)
            tempW += weight[tempPath[i]];
        double tempAvg = 1.0 * tempW / (tempPath.size() - 1);
        if(tempW > maxW) {
            maxW = tempW;
            maxAvg = tempAvg;
            path = tempPath;
        } else if(tempW == maxW && tempAvg > maxAvg) {
            maxAvg = tempAvg;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < (int)pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main() {
    string start, cityA, cityB;
    cin >> n >> m >> start;
    city2Index[start] = 0;
    index2City[0] = start;
    for(int i = 1; i < n; i++) {
        cin >> cityA >> weight[i];
        city2Index[cityA] = i;
        index2City[i] = cityA;
    }
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++) {
        cin >> cityA >> cityB;
        int cA = city2Index[cityA], cB = city2Index[cityB];
        cin >> G[cA][cB];
        G[cB][cA] = G[cA][cB];
    }
    Dijkstra(0);
    int rom = city2Index["ROM"];
    DFS(rom);
    printf("%d %d %d %d\n", numPath, d[rom], maxW, (int)maxAvg);
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << index2City[path[i]];
        if(i > 0) cout << "->";
    }
    return 0;
}