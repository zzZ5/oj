#include <cstring>
#include <cstdio>

bool judge(char[] str) {
    int countP = 0;
    int countT = 0;

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == 'P'){
            countP++;
        } else if(str[i] == 'T') {
            countT++;
        } else if(str[i] == 'A') {
            
        } else {
            return false;
        }

    }

}

int main() {
    int n;
    char str[110];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(judge(str)) {
            printf("YES\n")
        } else {
            printf("NO\n")
        }
    }
    return;
}