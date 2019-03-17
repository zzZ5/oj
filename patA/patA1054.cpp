#include <cstdio>
#include <map>
using namespace std;

map<int, int> hashTable;

int main() {
    int m, n, color;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &color);
            if(hashTable.find(color) == hashTable.end()) hashTable[color] = 1;
            else hashTable[color]++;
        }
    }
    int dominColor, maxNum = 0;
    for(map<int, int>::iterator it = hashTable.begin(); it != hashTable.end(); it++) {
        if(it->second > maxNum) {
            dominColor = it->first;
            maxNum = it->second;
        }
    }
    printf("%d\n",dominColor);
    return 0;
}