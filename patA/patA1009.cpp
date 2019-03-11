#include <cstdio>
#include <math.h>
const int MAXN = 1001;
const double MIN = 1e-8;

struct Poly{
    int exp;
    double cof;
}poly[MAXN];
double ans[MAXN*2] = {0.0};

int main() {
    int nA, nB;
    scanf("%d", &nA);
    for(int i = 0; i < nA; i++) {
        scanf("%d%lf", &poly[i].exp, &poly[i].cof);
    }
    scanf("%d", &nB);
    for(int i = 0; i < nB; i++) {
        int exp;
        double cof;
        scanf("%d%lf", &exp, &cof);
        for(int j = 0; j < nA; j++) {
            ans[poly[j].exp + exp] += poly[j].cof * cof;
        }
    }
    int count = 0;
    for(int i = 0; i < MAXN * 2; i++) {
        if(abs(ans[i]) > MIN) {
            count++;
        }
    }
    printf("%d", count);
    for(int i = MAXN *2 -1; i >= 0; i--) {
        if(abs(ans[i]) > MIN) {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;   
}