#include <cstdio>

int hashTable[101] = {0};

int main() {
    int n, score, query;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &score);
        hashTable[score]++; 
    }
    scanf("%d", &query);
    for(int i = 0; i < query; i++) {
        scanf("%d", &score);
        printf("%d", hashTable[score]);
        if(i < query - 1) {
            printf(" ");
        }
    }
    return 0;
}