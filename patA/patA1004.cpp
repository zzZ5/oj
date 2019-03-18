#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N = 101;

vector<int> Tree[N];
int h[N] = {0};
int leaf[N] = {0};
int maxH = 0;

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        maxH = max(maxH, h[front]);
        if(Tree[front].size() == 0) {
            leaf[h[front]]++;
        } else {
            for(int i = 0; i < (int)Tree[front].size(); i++) {
                h[Tree[front][i]] = h[front] + 1;
                q.push(Tree[front][i]);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int parent, k, child;
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            Tree[parent].push_back(child);
        }
    }
    h[1] = 1;
    BFS(1);
    for(int i = 1; i <= maxH; i++) {
        printf("%d", leaf[i]);
        if(i < maxH) printf(" ");
    }
    return 0;
}