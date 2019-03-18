#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50;

struct node {
    int data;
    node* lchild;
    node* rchild;
};

int pre[MAXN], in[MAXN], post[MAXN];
int n;

node* create(int preL, int preR, int inL, int inR) {
    if(preL > preR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = inL; k < inR; k++) {
        if(in[k] == pre[preL])
            break;
    }
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

int num = 0;

void postOrder(node* root) {
    if(!root) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d", root->data);
    if(num < n - 1) printf(" ");
    num ++;
}

int main() {
    scanf("%d", &n);
    char str[5];
    stack<int> st;
    int x, preInedx = 0, inIndex = 0;
    for(int i = 0; i < 2 * n; i++) {
        scanf("%s", str);
        if(strcmp(str, "Push") == 0) {
            scanf("%d", &x);
            pre[preInedx++] = x;
            st.push(x);
        } else {
            in[inIndex++] = st.top();
            st.pop();
        }
    }
    node* root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}



