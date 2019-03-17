#include <cstdio>
#include <stack>
using namespace std;
const int MAXN = 1001;

int array[MAXN];
stack<int> st;

int main() {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        while(!st.empty())
            st.pop();
        for(int j = 0; j < n; j++) {
            scanf("%d", &array[j]);
        }
        int cur = 0;
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            st.push(i);
            if((int)st.size() > m){
                flag = false;
                break;
            }
            while(!st.empty() && st.top() == array[cur]) {
                st.pop();
                cur++;
            }
        }
        if(flag && st.empty()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}