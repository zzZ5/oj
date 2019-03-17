#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 40001;
const int MAXC = 2501;

vector<int> course[MAXC];
char name[MAXN][5];

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    int n, k, c, courseID;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s %d", name[i], &c);
        for(int j = 0; j < c; j++) {
            scanf("%d", &courseID);
            course[courseID].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, (int)course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        //迭代遍历并没有下标索引效率高
        // for(vector<int>::iterator it = course[i].begin(); it != course[i].end(); it++) {
        //     printf("%s\n", name[*it]);
        // }
        for(int j = 0; j < (int)course[i].size(); j++) {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}