#include <cstdio>
const int MAXN = 1001;

int hashTable[MAXN] = {0};

int main() {
    int n;
    scanf("%d", &n);
    int team, member, score;
    for(int i = 0; i < n; i++) {
        scanf("%d-%d %d", &team ,&member, &score);
        hashTable[team] += score;
    }
    int index = 0;
    for(int i = 1; i < MAXN; i++) {
        if(hashTable[i] > hashTable[index]) {
            index = i;
        }
    }
    printf("%d %d\n", index, hashTable[index]);
    return 0;
}