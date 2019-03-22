#include <cstdio>

int n, k, ans = 0;
bool broken[101] = {false};

void dfs(int index) {
    if(index > n) return;
    if(broken[index]) return;
    if(index == n){
        ans++;
        return;
    }
    for(int i = 1; i <= 3; i++) {
        dfs(index + i);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    int a;
    for(int i = 0; i < k; i++) {
        scanf("%d", &a);
        broken[a] = true;
    }
    dfs(0);
    printf("%d\n",ans);
    return 0;
}