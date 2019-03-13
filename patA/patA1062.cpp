#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
    char id[10];
    int de, cai , sum;
    int grade;
} stu[100001];

bool cmp(Student a, Student b) {
    if(a.grade != b.grade) {
        return a.grade < b.grade;
    } else if(a.sum != b.sum) {
        return a.sum > b.sum;
    } else if(a.de != b.de) {
        return a.de > b.de;
    } else {
        return strcmp(a.id, b.id) < 0;
    }
}

int main() {
    int n, L, H;
    int count = 0;
    scanf("%d%d%d", &n, &L, &H);
    for(int i = 0; i < n; i++) {
        scanf("%s%d%d", stu[i].id, &stu[i].de, &stu[i].cai);
        stu[i].sum = stu[i].de + stu[i].cai;
        if(stu[i].cai >= L && stu[i].de >= L){
            count++;
            if(stu[i].de >= H && stu[i].cai >=H) {
                stu[i].grade = 1;
            } else if(stu[i].de >= H) {
                stu[i].grade = 2;
            } else if(stu[i].de >= stu[i].cai) {
                stu[i].grade = 3;
            } else {
                stu[i].grade = 4;
            }
        } else {
            stu[i].grade = 5;
        }
    }
    sort(stu, stu + n, cmp);
    printf("%d\n", count);
    for(int i = 0; i < count; i++) {
        printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
    }
    return 0;
}