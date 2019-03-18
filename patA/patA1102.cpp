#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 101;

struct Node {
    int lchild, rchild;
} node[MAXN];

int n, num = 0;

void printNode(int id) {
    printf("%d", id);
    num ++;
    if(num < n) printf(" ");
    else printf("\n");
}

void inOrder(int root) {
    if(root == -1) return;
    inOrder(node[root].lchild);
    printNode(root);
    inOrder(node[root].rchild);
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        printNode(front);
        if(node[front].lchild != -1) q.push(node[front].lchild);
        if(node[front].rchild != -1) q.push(node[front].rchild);
    }
}

void postOrder(int root) {
    if(root == -1) return;
    postOrder(node[root].lchild);
    postOrder(node[root].rchild);
    swap(node[root].lchild, node[root].rchild);
}

bool notRoot[MAXN] = {false};

int str2Num(char c) {
    if(c == '-') return -1;
    else {
        notRoot[c - '0'] = true;
        return c- '0';
    }
}

int findRoot() {
    for(int i = 0; i < n; i++)
        if(!notRoot[i])
            return i;
}

int main() {
    char lchild, rchild;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %c %c", &lchild, &rchild);
        node[i].lchild = str2Num(lchild);
        node[i].rchild = str2Num(rchild);
    }
    int root = findRoot();
    postOrder(root);
    num = 0;
    BFS(root);
    num = 0;
    inOrder(root);
    return 0;
}