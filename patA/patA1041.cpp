#include <cstdio>

int hashTable[10001] = {0};
int a[100001];

int main() {
    int n, ans = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        hashTable[a[i]]++;
    }
    for(int i = 0; i < n; i++) {
        if(hashTable[a[i]] == 1) {
            ans = a[i];
            break;
        }
    }
    if(ans == -1) {
        printf("None\n");
    } else{
        printf("%d\n", ans);
    }
    return 0;
}