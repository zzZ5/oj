// #include<cstdio>
// #include<math.h>
// const double MIN = 1e-8;
// const int MAX = 1001;
// int main() {
//     double a[MAX] = {0.0};
//     int na, nb, index;
//     double k;
//     scanf("%d", &na);
//     for(int i = 0; i < na; i++) {
//         scanf("%d", &index);
//         scanf("%lf", &a[index]);
//     }
//     scanf("%d", &nb);
//     int n = na + nb;
//     for(int i = 0; i < nb; i++) {
//         scanf("%d",  &index);
//         scanf("%lf", &k);
//         if(abs(a[index]) > MIN){
//             n--;
//         }
//         a[index] += k;
//         if(abs(a[index]) < MIN) {
//             n--;
//         }
//     }
//     printf("%d", n);
//     for(int i = MAX-1; i >= 0; i--) {
//         if(abs(a[i]) > MIN) {
//             printf(" %d %.1f", i, a[i]);
//         }
//     }
//     return 0;
// }


#include<cstdio>
#include<math.h>
const double MIN = 1e-8;
struct node {
    int index;
    double num;
    node *next;
};

int main() {
    node *headA = new node;
    headA->next = NULL;
    node *headB = new node;
    headB->next = NULL;
    node *A = headA;
    node *B = headB;
    node *temp;
    int na, nb, index, n;
    double num;
    scanf("%d", &na);
    for(int i = 0; i < na; i++) {
        scanf("%d%lf", &index, &num);
        temp = new node;
        temp->index = index;
        temp->num = num;
        temp->next = NULL;
        A->next = temp;
        A = A->next;
    }
    scanf("%d", &nb);
    for(int i = 0; i < nb; i++) {
        scanf("%d%lf", &index, &num);
        temp = new node;
        temp->index = index;
        temp->num = num;
        temp->next = NULL;
        B->next = temp;
        B = B->next;
    }
    n = na+nb;
    A = headA;
    B = headB;
    while(A->next && B->next){
        if(A->next->index > B->next->index){
            A = A->next;
        }else if(A->next->index == B->next->index) {
            A->next->num = A->next->num + B->next->num;
            if (abs(A->next->num) < MIN) {
                temp = A->next;
                A->next = A->next->next;
                delete(temp);
                n--;
            }
            //A = A->next 这句话出了问题，A已经到达下一位了，再下一位可能会导致越界
            B = B->next;
            n--;
        } else {
            temp = B->next;
            B->next = B->next->next;
            temp->next = A->next;
            A->next = temp;
        }
    }
    if(B->next) {
        A->next = B->next;
    }
    printf("%d", n);
    A = headA->next;
    while(A){
        printf(" %d %.1f", A->index, A->num);
        A = A->next;
    }
    return 0;
}