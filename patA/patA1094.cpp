#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 101;

vector<int> Node[MAXN];
int hashTable[MAXN] = {0};

void DFS(int index, int depth) {
    hashTable[depth]++;
    for(int i = 0; i < (int)Node[index].size(); i++) {
        DFS(Node[index][i], depth + 1);
    }
}

int main() {
    int n, m, parent, k ,child;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[parent].push_back(child);
        }
    }
    DFS(1, 1);
    int maxNum = 0, maxLevel = -1;
    for(int i = 1; i <= n; i++) {
        if(hashTable[i] > maxNum) {
            maxLevel = i;
            maxNum = hashTable[i];
        }
    }
    printf("%d %d\n", maxNum, maxLevel);
    return 0;
}