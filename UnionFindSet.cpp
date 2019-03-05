#include<cstdio>
const int MAX=100;

int father[MAX];
bool isRoot[MAX];

int findFather(int x) {
    if( x == father[x]) {
        return x;
    }else {
        return findFather(father[x]);
    }
}

int findAndCondenseFather(int x) {
    if( x == father[x]) {
        return x;
    } else {
        int F = findAndCondenseFather(father[x]);
        father[x] = F;
        return F;
    }
}

void Union(int a, int b) {
    int faA = findAndCondenseFather(a);
    int faB = findAndCondenseFather(b);
    if(faA != faB) {
        father[faA] = faB;
    }
}

void init(int n) {
    for(int i = 1; i <= n; i++) {
        father[i] = i;
        isRoot[i] = false;
    }
}

int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    init(n);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        Union(a, b);
    }
    for(int i = 1; i <= n; i++) {
        isRoot[findAndCondenseFather(i)] = true;
    }
    int ans=0;
    for(int i = 1; i <= n; i++) {
        if(isRoot[i]) {
            ans+=1;
        }
    }
    printf("%d\n", ans);
    return 0;
}