#include <cstdio>

struct Student {
    char name[15];
    char id[15];
    int score;
}temp, ansMax, ansMin;

int main() {
    int n;
    ansMax.score = -1;
    ansMin.score = 101;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s%s%d",&temp.name, &temp.id, &temp.score);
        if(temp.score > ansMax.score) {
            ansMax = temp;
        }
        if(temp.score < ansMin.score) {
            ansMin = temp;
        }
    }
    printf("%s %s\n", ansMax.name, ansMax.id);
    printf("%s %s\n", ansMin.name, ansMin.id);
    return 0;
}