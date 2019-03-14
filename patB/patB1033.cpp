#include <cstdio>
#include <cstring>
const int MAXN = 100001;

bool hashTable[256];
char str[MAXN];

int main() {
    scanf("%[^\n]", str);
    getchar();
    int len = strlen(str);
    memset(hashTable, true, sizeof(hashTable));
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
        hashTable[str[i]] = false;
    }
    scanf("%[^\n]", str);
    len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            if(hashTable[(str[i] - 'A' + 'a')] && hashTable['+']) {
                printf("%c", str[i]);
            }
        } else if(hashTable[str[i]]) {
            printf("%c", str[i]); 
        }
    }
    printf("\n");
    return 0;
}