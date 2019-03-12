#include <cstdio>
const int Galleon = 17 * 29;
const int Sickle = 29;

int main() {
    int a1, a2, a3;
    int b1, b2, b3;
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    int price = a1 * Galleon + a2 *Sickle + a3;
    int money = b1 * Galleon + b2 *Sickle + b3;
    int change = money - price;
    if(change < 0) {
        printf("-");
        change = -change;
    }
    printf("%d.%d.%d\n", change / Galleon, change % Galleon / Sickle, change % Sickle);
    return 0;
}