#include <cstdio>
#include <algorithm>
using namespace std;

struct Student {
    int GE, GI, sum;
    int rank, id;
    int choice[6];
}stu[40001];

struct School {
    int quota;
    int stuNum;
    int id[40001];
    int lastAdmit;
}sch[101];

bool cmpStu(Student a, Student b) {
    if(a.sum != b.sum) {
        return a.sum > b.sum;
    } else {
        return a.GE > b.GE;
    }
}

bool cmpId(int a, int b) {
    return stu[a].id < stu[b].id;
}

int main() {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < M; i++) {
        scanf("%d", &sch[i].quota);
        sch[i].stuNum = 0;
        sch[i].lastAdmit = -1;
    }
    for(int i = 0; i < N; i++) {
        stu[i].id = i;
        scanf("%d%d", &stu[i].GE, &stu[i].GI);
        stu[i].sum = stu[i].GE + stu[i].GI;
        for(int j = 0; j < K; j++) {
            scanf("%d", &stu[i].choice[j]);
        }
    }
    sort(stu, stu + N, cmpStu);
    for(int i = 0; i < N; i++) {
        if(i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE) {
            stu[i].rank = stu[i -1].rank;
        } else {
            stu[i].rank = i;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            int choice = stu[i].choice[j];
            int num = sch[choice].stuNum;
            int last = sch[choice].lastAdmit;
            if(num < sch[choice].quota || (last != -1 && stu[i].rank == stu[last].rank)) {
                sch[choice].id[num] = i;
                sch[choice].lastAdmit = i;
                sch[choice].stuNum++;
                break;
            }
        }
    }
    for(int i = 0; i < M; i++) {
        if(sch[i].stuNum > 0) {
            sort(sch[i].id, sch[i].id +sch[i].stuNum, cmpId);
            for(int j = 0; j < sch[i].stuNum; j++) {
                printf("%d", stu[sch[i].id[j]].id);
                if(j < sch[i].stuNum -1) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}