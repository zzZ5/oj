#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 101;
const int MAXE = 10001;
struct edge {
    int nodeA;
    int nodeB;
    int weight;
}e[MAXE];
bool cmp(edge a, edge b) {
    return a.weight < b.weight;
}

int father[MAXN];
int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    //路径压缩
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

int nodeNum, edgeNum;

int Kruskal() {
    int ans = 0, conEdge = 0;
    for(int i = 0; i < nodeNum; i++) {
        father[i] = i;
    }
    sort(e, e + edgeNum, cmp);
    for(int i = 0; i < edgeNum; i++) {
        int faA = findFather(e[i].nodeA);
        int faB = findFather(e[i].nodeB);
        if(faA != faB) {
            father[faA] = faB;
            ans += e[i].weight;
            conEdge++;
            if(conEdge == nodeNum - 1) {
                break;
            }
        }
    }
    if(conEdge != nodeNum-1) {
        return -1;
    } else {
        return ans;
    }
}

int main() {
    scanf("%d%d", &nodeNum, &edgeNum);
    for(int i = 0; i < edgeNum; i++) {
        scanf("%d%d%d", &e[i].nodeA, &e[i].nodeB, &e[i].weight);
    }
    int ans = Kruskal();
    printf("%d\n", ans);
    return 0;
}