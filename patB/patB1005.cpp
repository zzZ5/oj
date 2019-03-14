#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 101;

bool hashTable[MAXN] = {false};

bool cmp(int a, int b) {
    return a > b;
}

void Callatz(int n) {
    while(n != 1) {
        n = (n % 2 == 0 ? n / 2 : (n * 3 + 1) / 2);
        if(n < MAXN) hashTable[n] = true;
    }
}

int main() {
    int n, num[MAXN], count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        Callatz(num[i]);
    }
    for(int i = 0; i < n; i++) {
        if(!hashTable[num[i]]) {
            count++;
        }
    }
    sort(num, num + n, cmp);
    for(int i = 0; i < n; i++) {
        if(!hashTable[num[i]]) {
            printf("%d", num[i]);
            count--;
            if(count > 0) {
                printf(" ");
            }
        }
    }
    return 0;
}