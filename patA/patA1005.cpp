#include <cstdio>
#include <cstring>

char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void dfs(int n) {
    if(n / 10 == 0) {
        printf("%s",num[n % 10]);
        return;
    }
    dfs(n / 10);
    printf(" %s", num[n % 10]);
}

int main() {
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    int sum;
    for(int i = 0; i < len; i++) {
        sum += str[i] - '0';
    }
    dfs(sum);
    return 0;
}



