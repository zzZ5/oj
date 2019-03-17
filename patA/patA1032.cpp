#include <cstdio>
#include <cstring>
const int max = 100001;

struct Node {
    char data;
    int next;
    bool flag;
}node[max];

int main() {
    for(int i = 0; i < max; i++)
        node[i].flag = false;
    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    int adress, next;
    char data;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &adress, &data, &next);
        node[adress].data = data;
        node[adress].next = next;
    }
    int p;
    for(p = s1; p != -1; p = node[p].next)
        node[p].flag = true;
    for(p = s2; p != -1; p = node[p].next)
        if(node[p].flag)
            break;
    if(p != -1) printf("%05d\n", p);
    else printf("-1\n");
    return 0;
}