#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100001;

int main() {
    int n, pos[MAXN], num;
    scanf("%d", &n);
    int disloc = n - 1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        pos[num] = i;
        if(num == i && num != 0) disloc--;
    }
    int ans = 0;
    int temp = 1;
    while(disloc > 0) {
        if(pos[0] == 0) {
            while(temp < n) {
                if(pos[temp] != temp) {
                    swap(pos[0], pos[temp]);
                    ans++;
                    break;
                }
                temp++;
            }
        }
        while(pos[0] != 0) {
            swap(pos[0], pos[pos[0]]);
            ans++;
            disloc--;
        }
    }
    printf("%d\n", ans);
    return 0;
}