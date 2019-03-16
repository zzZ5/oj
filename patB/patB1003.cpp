#include <cstring>
#include <cstdio>

int main() {
    int n;
    char str[101];
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        scanf("%s", &str);
        int len = strlen(str);
        int numP = 0, numT = 0, other = 0;
        int posP = -1, posT = -1;
        for(int i = 0; i < len; i++) {
            if(str[i] == 'P') {
                numP++;
                posP = i;
            } else if(str[i] == 'T') {
                numT++;
                posT = i;
            } else if(str[i] != 'A') {
                other++;
            }
        }
        if(numP != 1 || numT != 1 || other != 0 ||posT - posP <= 1) {
            printf("NO\n");
            continue;
        }
        int leftA = posP, midA = posT - posP - 1, rightA = len - posT - 1;
        if(rightA == leftA * midA) {
            printf("YES\n");
        } else {
            printf("NO\n");            
        }
    }
    return 0;
}