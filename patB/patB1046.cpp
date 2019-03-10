#include <cstdio>

int main() {
    int n;
    int drinkA = 0, drinkB = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a1, a2, b1, b2;
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        if(a1 + b1 == a2 && a1 + b1 != b2){
            drinkB++;
        }
        if(a1 + b1 != a2 && a1 + b1 == b2){
            drinkA++;
        }
    }
    printf("%d %d\n", drinkA, drinkB);
    return 0;
}