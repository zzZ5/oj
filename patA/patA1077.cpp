#include <cstdio>
#include <cstring>

int main() {
    int n;
    char s[100][256];
    int minLen = 256;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        scanf("%[^\n]", s[i]);
        getchar();
        int len = strlen(s[i]);
        minLen = len < minLen ? len : minLen;
        for(int j = 0; j < len / 2; j++) {
            char temp = s[i][j];
            s[i][j] = s[i][len -1 -j];
            s[i][len -1 -j] = temp;
        }
    }
    int ans = 0;
    for(int i = 0; i < minLen; i++) {
        char c = s[0][i];
        bool same = true;
        for(int j = 0; j < n; j++) {
            if(c != s[j][i]) {
                same = false;
                break;
            }
        }
        if(same) {
            ans++;
        } else {
            break;
        }
    }
    if(ans) {
        for(int i = ans - 1; i >= 0; i--) {
            printf("%c", s[0][i]);
        }
    } else {
        printf("nai");
    }
    return 0;
}