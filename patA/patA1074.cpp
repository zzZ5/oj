#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100001;

struct Node {
    int adress, data, next;
    int order;
}node[MAXN];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    for(int i = 0; i < MAXN; i++) {
        node[i].order = MAXN;
    }
    int begin, n, k, adress;
    scanf("%d%d%d", &begin, &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &adress);
        scanf("%d%d", &node[adress].data, &node[adress].next);
        node[adress].adress = adress;
    }
    int p = begin, count = 0;
    while(p != -1) {
        node[p].order = count++;
        p = node[p].next;
    }
    sort(node, node + MAXN, cmp);
    n = count;
    for(int i = 0; i < n / k; i++) {
        for(int j = (i + 1) * k - 1; j > i * k; j--) {
            printf("%05d %d %05d\n", node[j].adress, node[j].data, node[j - 1].adress);
        }
        printf("%05d %d ", node[i * k].adress, node[i * k].data);
        if(i < n / k - 1) {
            printf("%05d\n", node[(i + 2) * k - 1].adress);
        } else {
            if(n % k == 0) {
                printf("-1\n");
            } else {
                printf("%05d\n", node[(i + 1) * k].adress);
                for(int i = n / k * k; i < n; i++) {
                    printf("%05d %d ", node[i].adress, node[i].data);
                    if(i < n - 1) {
                        printf("%05d\n", node[i + 1].adress);
                    } else {
                        printf("-1\n");
                    }
                }
            }
        }
    }
    return 0;
}