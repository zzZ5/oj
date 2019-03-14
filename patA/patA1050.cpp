#include <cstdio>
#include <cstring>
const int MAXN = 10001;

bool hashTable[256] = {false};

int main() {
    char str1[MAXN], str2[MAXN];
    scanf("%[^\n]", str1);
    getchar();
    scanf("%[^\n]", str2);
    int len1 = strlen(str1), len2 = strlen(str2);
    for(int i = 0; i < len2; i++) {
        hashTable[str2[i]] = true;
    }
    for(int i = 0; i < len1; i++) {
        if(!hashTable[str1[i]]) {
            printf("%c", str1[i]);
        }
    }
    return 0;
}