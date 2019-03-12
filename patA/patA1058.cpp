#include <cstdio>

int main() {
    int a[3];
    int b[3];
    scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
    int carry = 0;
    a[2] = a[2] + b[2];
    carry = a[2] / 29;
    a[2] %= 29;
    a[1] = a[1] + b[1] + carry;
    carry = a[1] / 17;
    a[1] %= 17;
    a[0] = a[0] + b[0] +carry;
    printf("%d.%d.%d\n", a[0], a[1], a[2]);
    return 0;
}