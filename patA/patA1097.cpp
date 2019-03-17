#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 100001;
const int MAX_VALUE = 10001;

struct Node {
    int adress, data, next;
    int order;
}node[MAX_N];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

bool isExist[MAX_VALUE] = {false};

int main() {
    for(int i = 0; i < MAX_N; i++)
        node[i].order = 2 * MAX_N;
    int n, begin, adress;
    scanf("%d%d", &begin, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &adress);
        scanf("%d%d", &node[adress].data, &node[adress].next);
        node[adress].adress = adress;
    }

    int validNum = 0, removeNum = 0, p = begin;
    while(p != -1) {
        if(!isExist[abs(node[p].data)]) {
            isExist[abs(node[p].data)] = true;
            node[p].order = validNum++;
        } else {
            node[p].order = MAX_N + removeNum++;
        }
        p = node[p].next;
    }
    sort(node, node + MAX_N, cmp);
    int count = validNum + removeNum;
    for(int i = 0; i < count; i++) {
        if(i != validNum - 1 && i != count - 1) {
            printf("%05d %d %05d\n", node[i].adress, node[i].data, node[i + 1].adress);
        } else {
            printf("%05d %d -1\n", node[i].adress, node[i].data);
        }
    }
    return 0;
}