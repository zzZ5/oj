#include <cstdio>
#include <cstring>
const int MAXN = 1001;

int hashTable[27] = {0};

int main() {
    char str[MAXN];
    scanf("%[^\n]", str);
    int len = strlen(str);
    char c;
    for(int i = 0; i < len; i++) {
        c = str[i];
        if(c >= 'a' && c <= 'z') {
            hashTable[c - 'a']++;
        } else if(c >= 'A' && c <= 'Z') {
            hashTable[c - 'A']++;
        }
    }
    int index = 0;
    for(int i = 0; i < 26; i++) {
        if(hashTable[i] > hashTable[index]) {
            index = i;
        }
    }
    printf("%c %d\n", 'a' + index, hashTable[index]);
    return 0;
}