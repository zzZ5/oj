#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct bigInt {
    int d[1001];
    int len;
    bigInt() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bigInt change(char str[]) {
    int len = strlen(str);
    bigInt ret;
    ret.len = len;
    for(int i = 0; i < len; i++) 
        ret.d[i] = str[len - 1 - i] - '0';
    return ret;
}

bigInt add(bigInt a, bigInt b) {
    bigInt ret;
    int carry = 0;
    for(int i = 0; i < a.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        ret.d[ret.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0)
        ret.d[ret.len++] = carry;
    return ret;
}

bool Judge(bigInt a) {
    for(int i = 0; i < a.len / 2; i++)
        if(a.d[i] != a.d[a.len - 1 - i])
            return false;
    return true;
}

void printBigInt(bigInt a) {
    for(int i = a.len - 1; i >= 0; i--) 
        printf("%d", a.d[i]);
}

int main() {
    char str[1001];
    int n;
    scanf("%s %d", str, &n);
    bigInt a = change(str);
    for(int i = 0; i < n; i++) {
        if(Judge(a)) {
            printBigInt(a);
            printf("\n%d\n", i);
            return 0;
        }
        bigInt b = a;
        reverse(b.d, b.d + b.len);
        a = add(a, b);
    }
    printBigInt(a);
    printf("\n%d\n", n);
    return 0;
}