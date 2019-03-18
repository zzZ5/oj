#include <cstdio>
#include <math.h>
#include <vector>
using namespace std;
const int MAXN = 100001;
const double INF = 1e12;

vector<int> Node[MAXN];
int n, num;
double p, r, ans = INF;

void DFS(int index, int depth) {
    if (Node[index].size() == 0) {
        double price = p * pow(1 + r, depth);
        if(price < ans) {
            ans = price;
            num = 1;
        } else if (price == ans) {
            num++;
        }
        return;
    }
    for(int i = 0; i < (int)Node[index].size(); i++) {
        DFS (Node[index][i], depth + 1);
    }
}

int main() {
    int k, child;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[i].push_back(child);
        }
    }
    DFS(0, 0);
    printf("%.4f %d\n", ans, num);
    return 0;
}