#include <cstdio>
#include <vector>
using namespace std;

struct node {
    int data;
    node *lchild, *rchild;
};

void insert(node *&root, int data) {
    if(!root){
        root = new node;
        root->data = data;
        root->lchild = root->rchild = NULL;
        return;
    }
    if(root->data > data) insert(root->lchild, data);
    else insert(root->rchild, data);
}

void preOrder(node *root, vector<int> &vi, bool mirror) {
    if(!root) return;
    vi.push_back(root->data);
    if(mirror) {
        preOrder(root->rchild, vi, mirror);
        preOrder(root->lchild, vi, mirror);
    }else {
        preOrder(root->lchild, vi, mirror);
        preOrder(root->rchild, vi, mirror);
    }
}

void postOrder(node *root, vector<int> &vi, bool mirror) {
    if(!root) return;
    if(mirror) {
        postOrder(root->rchild, vi, mirror);
        postOrder(root->lchild, vi, mirror);
    }else {
        postOrder(root->lchild, vi, mirror);
        postOrder(root->rchild, vi, mirror);
    }
    vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;
int main() {
    int n, data;
    node *root = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre, false);
    preOrder(root, preM, true);
    postOrder(root, post, false);
    postOrder(root, postM, true);
    if(origin == pre) {
        printf("YES\n");
        for(int i = 0; i < post.size(); i++) {
            printf("%d", post[i]);
            if(i<post.size() - 1) {
                printf(" ");
            }
        }
    } else if(origin == preM) {
        printf("YES\n");
        for(int i = 0; i < postM.size(); i++) {
            printf("%d", postM[i]);
            if(i < postM.size() - 1) printf(" ");
        }
    } else printf("NO\n");
    return 0;
}