#include <cstdio>

int change(char a) {
    int ret = -1;
    switch (a){
        case 'B':
            ret = 0;
            break;
        case 'C':
            ret = 1;
            break;
        case 'J':
            ret = 2;
            break;
    }
    return ret;
}

int main() {
    int n;
    char  c1, c2;
    char mp[3] = {'B', 'C', 'J'};
    int k1, k2;
    int timeA[3] = {0}, timeB[3] = {0};
    int handA[3] = {0}, handB[3] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %c %c", &c1, &c2);
        k1 = change(c1);
        k2 = change(c2);
        if((k1 + 1) % 3 == k2) {
            timeA[0]++;
            timeB[2]++;
            handA[k1]++;
        } else if(k1 == k2) {
            timeA[1]++;
            timeB[1]++;
        }else {
            timeB[0]++;
            timeA[2]++;
            handB[k2]++;
        }
    }
    printf("%d %d %d\n", timeA[0], timeA[1], timeA[2]);
    printf("%d %d %d\n", timeB[0], timeB[1], timeB[2]);
    int idA = 0, idB = 0;
    for(int i = 1; i < 3; i++) {
        if(handA[i] > handA[idA]) idA = i;
        if(handB[i] > handB[idB]) idB = i;
    }
    printf("%c %c\n", mp[idA], mp[idB]);
    return 0;
}