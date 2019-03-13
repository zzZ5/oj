#include <cstdio>
#include<map>
#include <algorithm>
using namespace std;

int cur;
struct Student{
    int id;
    int grade[4];
}stu[2001];
bool cmp(Student a, Student b) {
    return a.grade[cur] > b.grade[cur];
}

struct rankof4Cla{
    int rank[4];
};

char course[4] = {'A' ,'C', 'M', 'E'};
map<int, rankof4Cla> Rank;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3] + 1) / 3;
        rankof4Cla r;
        Rank.insert(make_pair(stu[i].id,r));
    }
    for(cur = 0; cur < 4; cur++) {
        sort(stu, stu + n, cmp);
        map<int, rankof4Cla>::iterator it= Rank.find(stu[0].id);
        it->second.rank[cur] = 1;
        for(int i = 1; i < n; i++) {
            it = Rank.find(stu[i].id);
            if(stu[i].grade[cur] == stu[i - 1].grade[cur]) {
                it->second.rank[cur] = Rank.find(stu[i - 1].id)->second.rank[cur];
            } else {
                it->second.rank[cur] = i + 1;
            }
        }
    }
    int query;
    for(int i = 0; i < m; i++) {
        scanf("%d", &query);
        map<int, rankof4Cla>::iterator it= Rank.find(query);
        if(it == Rank.end()) {
            printf("N/A\n");
        } else {
            int k = 0;
            for(int j = 0; j < 4; j++) {
                if(it->second.rank[j] < it->second.rank[k]) {
                    k = j;
                }
            }
            printf("%d %c\n", it->second.rank[k], course[k]);
        }
    }
    return 0;
}