#include <cstdio>
#include <cstring>

struct User{
    char name[20], pW[20];
    bool ischange;
}users[1001];

void judege(User &user, int &count) {
    int len = strlen(user.pW);
    for(int i = 0; i < len; i++) {
        if(user.pW[i] == '1') {
            user.pW[i] = '@';
            user.ischange = true;
        } else if(user.pW[i] == '0') {
            user.pW[i] = '%';
            user.ischange = true;
        } else if(user.pW[i] == 'l') {
            user.pW[i] = 'L';
            user.ischange = true;
        } else if(user.pW[i] == 'O') {
            user.pW[i] = 'o';
            user.ischange = true;
        }
    }
    if(user.ischange) {
        count++;
    }
}

int main() {
    int n, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %s", users[i].name, users[i].pW);
        users[i].ischange = false;
        judege(users[i], count);
    }
    if(count == 0) {
        if(n == 1) {
            printf("There is %d account and no account is modified", n);
        } else{
            printf("There are %d accounts and no account is modified", n);
        }
    } else {
        printf("%d\n", count);
        for(int i = 0; i < n; i++) {
            if(users[i].ischange) {
                printf("%s %s\n", users[i].name, users[i].pW);
            }
        }
    }
    return 0;
}