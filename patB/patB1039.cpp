#include <cstdio>
#include <cstring>
const int MAXN = 1001;

int hashTable[256] = {0};

int main() {
    char str1[MAXN];
    char str2[MAXN];
    scanf("%s %s", str1, str2);
    int miss = 0;
    int len1 =strlen(str1), len2 = strlen(str2);
    for(int i = 0; i < len1; i++) {
        hashTable[str1[i]]++;
    }
    for(int i = 0; i < len2; i++) {
        if(hashTable[str2[i]] == 0) {
            miss++;
        } else{
            hashTable[str2[i]]--;
        }
    }
    if(miss == 0){
        printf("Yes %d\n", len1 - len2);
    } else {
        printf("No %d\n", miss);
    }
    return 0;
}