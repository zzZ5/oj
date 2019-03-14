#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 501;
const int INF = 0x3fffffff;

struct Station {
    double price, dis;
}sta[MAXN];

bool cmp(Station a, Station b) {
    return a.dis < b.dis;
}

int main() {
    int n;
    double Cmax, D, Davg;
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    }
    sta[n].price = 0;
    sta[n].dis = D;
    sort(sta, sta + n, cmp);
    if(sta[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
    } else {
        int cur = 0;
        double ans = 0, nowTank = 0, maxDis = Cmax * Davg;
        while(cur < n) {
            int k = -1;
            double minPrice = INF;
            for(int i = cur + 1; i <= n && (sta[i].dis - sta[cur].dis <= maxDis); i++) {
                if(sta[i].price < minPrice) {
                    minPrice = sta[i].price;
                    k = i;
                }
                if(sta[i].price < sta[cur].price){
                    break;
                }
            }
            if(k == -1) {
                break;
            }
            double need = (sta[k].dis - sta[cur].dis) / Davg;
            if(sta[cur].price > minPrice) {
                if(nowTank < need) {
                    ans += (need - nowTank) * sta[cur].price;
                    nowTank = 0;
                } else {
                    nowTank -= need;
                }
            } else {
                ans += (Cmax - nowTank) * sta[cur].price;
                nowTank = Cmax - need;
            }
            cur = k;
        }
        if(cur == n) {
            printf("%.2f\n", ans);
        } else {
            printf("The maximum travel distance = %.2f\n", sta[cur].dis + maxDis);
        }
    }
    return 0;
}