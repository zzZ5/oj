#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 101;

struct Node {
    int data;
    int lchild, rchild;
}node[MAXN];

int n, in[MAXN], num = 0;

void inOrder(int root) {
    if(root == -1) return;
    inOrder(node[root].lchild);
    node[root].data = in[num++];
    inOrder(node[root].rchild);
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    num = 0;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        printf("%d", node[front].data);
        if(++num < n) printf(" ");
        if(node[front].lchild != -1) q.push(node[front].lchild);
        if(node[front].rchild != -1) q.push(node[front].rchild);
    }
}

int main() {
    int lchild, rchild;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &lchild, &rchild);
        node[i].lchild = lchild;
        node[i].rchild = rchild;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    sort(in, in + n);
    inOrder(0);
    BFS(0);
    return 0;
}