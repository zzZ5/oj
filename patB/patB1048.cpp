#include <cstdio>
#include <cstring>
const int MAXN = 101;

int main() {
    char A[MAXN], B[MAXN], ans[MAXN];
    scanf("%s %s", A, B);
    int lenA = strlen(A), lenB = strlen(B);
    int len = lenA > lenB ? lenA : lenB;
    for(int i = 0; i < len; i++) {
        int numA = i < lenA ? A[lenA - 1 - i] - '0' : 0;
        int numB = i < lenB ? B[lenB - 1 - i] - '0' : 0;
        if(i % 2 == 0) {
            int temp = (numA + numB) % 13;
            if(temp == 10) {
                ans[i] = 'J';
            } else if(temp == 11) {
                ans[i] = 'Q';
            } else if(temp == 12) {
                ans[i] = 'K';
            } else {
                ans[i] = temp + '0';
            }
        } else {
            int temp = numB - numA;
            if(temp < 0) {
                temp += 10;
            }
            ans[i] = temp + '0';
        }
    }
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", ans[i]);
    }
    return 0;
}