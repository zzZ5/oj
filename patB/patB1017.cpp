#include <cstdio>
#include <cstring>

struct bigInt {
    int d[1001];
    int len;
    bigInt() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bigInt change(char str[]) {
    bigInt a;
    a.len = strlen(str);
    for(int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - i -1] - '0';
    }
    return a;
}

bigInt divide(bigInt a, int b, int &r) {
    bigInt c;
    r = 0;
    c.len = a.len;
    for(int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        if(r < b) c.d[i] = 0;
        else {
            c.d[i]= r / b;
            r = r % b;
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) c.len--;
    return c;
}

void printBigInt(bigInt a) {
    for(int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
}

int main() {
    char str1[1001];
    int b, r;
    scanf("%s %d", str1, &b);
    bigInt a = change(str1);
    printBigInt(divide(a, b, r));
    printf(" %d", r);
    return 0;
}