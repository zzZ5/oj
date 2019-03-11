#include <cstdio>
const int N = 54;
char mp[5] = {'S', 'H', 'C', 'D', 'J'};
int start[N], end[N], next[N];

int main() {
    int k;
    scanf("%d", &k);
    for(int i = 0; i < N; i++) {
        start[i] = i;
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &next[i]);
        next[i] = next[i] - 1;
    }
    for(int step = 0; step < k; step++) {
        for(int i = 0; i < N; i++) {
            end[next[i]] = start[i]; 
        }
        for(int i = 0; i < N; i++) {
            start[i] = end[i];
        }
    }
    for(int i = 0; i < N; i++) {
        printf("%c%d", mp[start[i]/13], start[i] % 13 +1);
        if(i < N - 1){
            printf(" ");
        }
    }
    return 0;
}