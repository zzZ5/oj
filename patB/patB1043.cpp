#include <cstdio>
#include <cstring>
const int MAXN = 10001;

char dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
int hashTable[6] = {0};

int main() {
    char str[MAXN];
    scanf("%[^\n]", str);
    int len = strlen(str);
    int count = 0;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < 6; j++) {
            if(str[i] == dict[j]) {
                hashTable[j]++;
                count++;
            }
        }
    }
    while(count > 0) {
        for(int i = 0; i < 6; i++) {
            if(hashTable[i] > 0) {
                printf("%c", dict[i]);
                hashTable[i]--;
                count--;
            }
        }
    }
    printf("\n");
    return 0;
}