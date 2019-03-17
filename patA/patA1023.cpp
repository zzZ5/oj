#include <cstdio>
#include <cstring>

struct bigInt {
    int d[21];
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

bigInt multi(bigInt a, int b) {
    bigInt ret;
    int carry = 0;
    for(int i = 0; i < a.len; i++) {
        int temp = a.d[i] * b + carry;
        ret.d[ret.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0) {
        ret.d[ret.len++] = carry % 10;
        carry = carry / 10;
    }
    return ret;
}

bool Judge(bigInt a, bigInt b) {
    if(a.len != b.len) return false;
    int hashTable[10] = {0};
    for(int i = 0; i < a.len; i++) {
        hashTable[a.d[i]]++;
        hashTable[b.d[i]]--;
    }
    for(int i = 0; i < 10; i++)
        if(hashTable[i] != 0) return false;
    return true;
}

void printBigInt(bigInt a) {
    for(int i = a.len - 1; i >= 0; i--) 
        printf("%d", a.d[i]);
}

int main() {
    char str[21];
    scanf("%s", str);
    bigInt a = change(str);
    bigInt mul = multi(a, 2);
    if(Judge(a, mul)) printf("Yes\n");
    else printf("No\n");
    printBigInt(mul);
    return 0;
}