#include <cstdio>
#include <math.h>
const int N = 11001;

bool isPrime(int n) {
    if(n <= 1) return false;
    int sqr = (int)sqrt(n * 1.0);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

bool hashTable[N] = {false};

int main() {
    int n, Tsize, a;
    scanf("%d%d", &Tsize, &n);
    while(!isPrime(Tsize)){
        Tsize++;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        int M = a % Tsize;
        if(!hashTable[M]) {
            hashTable[M] = true;
            printf("%d", M);
        } else {
            int step;
            for(step = 1; step < Tsize; step++) {
                M = (a + step * step) % Tsize;
                if(!hashTable[M]) {
                    hashTable[M] = true;
                    printf("%d", M);
                    break;
                }
            }
            if(step >= Tsize) printf("-");
        }
        if(i < n -1) printf(" ");
    }
    return 0;
}