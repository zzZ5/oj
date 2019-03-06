#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1000;
struct Node {
    int id,layer;
};
vector<Node> adj[MAX];
bool visit[MAX];

int BFS(int s, int maxLayer) {
    memset(visit, false, sizeof(visit));
    queue<Node> q;
    int forwarding = 0;
    Node start = {
        .id = s,
        .layer = 0
    };
    q.push(start);
    visit[s] = true;
    while(!q.empty()) {
        start = q.front();
        q.pop();
        for(int i = 0; i < adj[start.id].size(); i++) {
            Node next = adj[start.id][i];
            next.layer = start.layer+1;
            if(!visit[next.id] && next.layer <= maxLayer) {
                q.push(next);
                visit[next.id] = true;
                forwarding++;
            }
        }
    }
    return forwarding;
}


int main() {
    Node user;
    int n, maxLayer, followNum, id, forwarding;
    scanf("%d%d", &n, &maxLayer);
    for(int i = 1; i <= n; i++) {
        user.id = i;
        scanf("%d", &followNum);
        for(int j = 0; j < followNum; j++) {
            scanf("%d", &id);
            adj[id].push_back(user);
        }
    }
    int queryNum, s;
    scanf("%d", &queryNum);
    for(int i = 0; i < n; i++) {
        scanf("%d", &id);
        forwarding = BFS(id, maxLayer);
        printf("%d\n", forwarding);
    }
    return 0;
}
