#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;
const int MAXN = 100001;

int C; 

struct Student {
    int id;
    char name[10];
    int score;
}stu[MAXN];
bool cmp(Student a, Student b) {
    if(C == 1){
        return a.id < b.id;
    } else if(C == 2) {
        int s = strcmp(a.name, b.name);
        if(s != 0) {
            return s < 0;
        } else {
            return a.id < b.id;
        }
    } else {
        if(a.score != b.score) {
            return a.score < b.score;
        } else {
            return a.id < b.id;
        }
    }
}

int main() {
    int n;
    scanf("%d%d", &n, &C);
    for(int i = 0; i < n; i++) {
        scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].score);
    }
    sort(stu, stu + n, cmp);
    for(int i = 0; i < n; i++) {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }
    return 0;
}