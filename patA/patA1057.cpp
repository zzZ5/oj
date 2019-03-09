#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN = 100001;
const int sqrN = 316;

stack<int> st;
int block[sqrN];
int table[MAXN];
int n;

int PeekMedian(int median) {
    int sum = 0, idx = 0;
    while(sum + block[idx] < median){
        sum += block[idx++];
    }
    int num = idx * sqrN;
    while(sum + table[num] < median) {
        sum += table[num++];
    }
    return num;
}

void push(int x) {
    st.push(x);
    block[x / sqrN]++;
    table[x]++;
}

int pop() {
    int x = st.top();
    st.pop();
    block[x / sqrN]--;
    table[x]--;
    return x;
}

int main() {
    int x, n;
    memset(block, 0, sizeof(block));
    memset(table, 0, sizeof(table));
    char cmd[20];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s",cmd);
        if(strcmp(cmd, "Push") == 0) {
            scanf("%d", &x);
            push(x);
        } else if(strcmp(cmd, "Pop") == 0) {
            if(st.empty()){
                printf("Invalid\n");
            }else {
                x = pop();
                printf("%d\n", x);
            }
        }else {
            if(st.empty()){
                printf("Invalid\n");
            }else {
                int median = (st.size() + 1) / 2;
                x = PeekMedian(median);
                printf("%d\n", x);
            }
        }
    }
    return 0;
}