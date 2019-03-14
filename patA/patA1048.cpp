#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1001;

int hashTable[MAXN] = {0};

int main() {
    int n, price, money;
    scanf("%d %d", &n, &price);
    for(int i = 0; i < n; i++) {
        scanf("%d", &money);
        hashTable[money]++;
    }
    bool flag = false;
    for(int i = 1; i < price; i++) {
        if(hashTable[i] && hashTable[price - i]){
            if(i == price - i && hashTable[i] < 2){
                continue;
            } else {
                printf("%d %d\n", i, price - i);
                flag = true;
                break;
            }
        }
    }
    if(!flag) {
        printf("No Solution\n");
    }
    return 0;
}