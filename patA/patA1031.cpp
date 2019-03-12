#include <cstdio>
#include <cstring>

int main() {
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    int k = (len + 2) / 3;
    int space = len - k * 2;
    for(int i = 0; i < k-1; i++) {
        printf("%c", str[i]);
        for(int j = 0; j < space; j++) {
            printf(" ");
        }
        printf("%c", str[len - i -1]);
        printf("\n");
    }
    for(int i = 0; i < (space + 2); i++) {
        printf("%c", str[k + i -1]);
    }
    return 0;
}