#include <cstdio>
#include <math.h>
#include <vector>
using namespace std;
const int MAXN = 100001;

vector<int> child[MAXN];

int n, maxDepth, num;
double p, r;

void DFS(int index, int depth) {
    if(child[index].size() == 0) {
        if(depth > maxDepth) {
            maxDepth = depth;
            num = 1;
        } else if(depth == maxDepth) {
            num++;
        }
        return;
    }
    for(int i = 0; i < (int)child[index].size(); i++) {
        DFS(child[index][i], depth + 1);
    }
}

int main() {
    int father, root;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0; i < n; i++) {
        scanf("%d", &father);
        if(father != -1) {
            child[father].push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, 0);
    printf("%.2f %d\n", p * pow(1 + r, maxDepth), num);
    return 0;
}