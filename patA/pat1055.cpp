#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
int age[201] = {0};

struct person {
    char name[10];
    int age, worth;
} ps[MAXN], valid[MAXN];

bool cmp(person a, person b) {
    if(a.worth != b.worth) {
        return a.worth > b.worth;
    } else if(a.age != b.age) {
        return a.age < b.age;
    } else{
        return strcmp(a.name, b.name) < 0;
    }
}

int main() {
    int n, query;
    scanf("%d%d", &n, &query);
    for(int i = 0; i < n; i++) {
        scanf("%s%d%d", ps[i].name, &ps[i].age, &ps[i].worth);
    }
    sort(ps, ps + n, cmp);
    int validNum = 0;
    for(int i = 0; i < n; i++) {
        if(age[ps[i].age] < 100) {
            age[ps[i].age] ++;
            valid[validNum++] = ps[i];
        }
    }
    int m, ageL, ageR;
    for(int i = 0; i < query; i++) {
        scanf("%d%d%d", &m, &ageL, &ageR);
        printf("Case #%d:\n", i + 1);
        int printNum = 0;
        for(int j = 0; j < validNum && printNum < m; j++) {
            if(valid[j].age >= ageL && valid[j].age <=ageR) {
                printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);
                printNum++;
            }
        }
        if(printNum == 0) {
            printf("None\n");
        }
    }
    return 0;
}

