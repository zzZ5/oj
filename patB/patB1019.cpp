#include <cstdio>
#include <algorithm>
using namespace std;
const int DIGIT = 4;
    
bool cmp(int a,int b) {
    return a > b;
}
void toArray(int n, int num[]) {
    for(int i = 0; i < DIGIT; i++){
        num[i] = n % 10;
        n = n / 10;
    }
}
int toNumber(int num[]) {
    int n = 0;
    for(int i = 0; i < DIGIT; i++){
        n = n * 10 + num[i];
    }
    return n;
}

int main(){
    int n, min, max;
    int num[DIGIT];
    scanf("%d", &n);
    do {
        toArray(n, num);
        sort(num, num + DIGIT);
        min = toNumber(num);
        sort(num, num + DIGIT, cmp);
        max = toNumber(num);
        n = max - min;
        printf("%04d - %04d = %04d\n", max, min, n);
    }while(n != 0 && n != 6174);
    return 0;
}