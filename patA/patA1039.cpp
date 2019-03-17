#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 40001;
const int M = 26 * 26 * 26 * 10 + 1;

vector<int> selectCourse[M];

int getID(char name[]) {
    int id;
    for(int i = 0; i < 3; i++)
        id = id * 26 + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}

int main() {
    int n, k;
    char name[5];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        int course, x;
        scanf("%d %d", &course, &x);
        for(int j = 0; j < x; j++) {
            scanf("%s", name);
            int id = getID(name);
            selectCourse[id].push_back(course);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        int id = getID(name);
        sort(selectCourse[id].begin(), selectCourse[id].end());
        printf("%s %d", name, (int)selectCourse[id].size());
        //迭代遍历并没有下标索引效率高
        // for(vector<int>::iterator it = selectCourse[id].begin(); it != selectCourse[id].end(); it++) {
        //     printf(" %d", (int)*it);
        // }
        for(int j = 0; j < (int)selectCourse[id].size(); j++) {
            printf(" %d", selectCourse[id][j]);
        }
        printf("\n");
    }
    return 0;
}