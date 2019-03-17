#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000;
struct Node {
    int adress, data, next;
    bool flag;
}node[maxn];

bool cmp(Node a, Node b){
    if(!a.flag || !b.flag) return a.flag > b.flag;
    else return a.data < b.data;
}

int main() {
    for(int i = 0; i > maxn; i++)
        node[i].flag = false;
    int n, begin, address, data, next;
    scanf("%d%d", &n, &begin);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &address, &data, &next);
        node[address].adress = address;
        node[address].data = data;
        node[address].next = next;
    }
    int count = 0;
    for(int p = begin; p != -1; p = node[p].next) {
        node[p].flag = true;
        count++;
    }
    if(!count) printf("0 -1");
    else {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].adress);
        int i;
        for(i = 0; i < count - 1; i++)
            printf("%05d %d %05d\n", node[i].adress, node[i].data, node[i+1].adress);
        printf("%05d %d -1\n", node[i].adress, node[i].data);
    }
    return 0;
}