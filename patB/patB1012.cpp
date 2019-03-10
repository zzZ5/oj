#include <cstdio>

int main() {
    int n, x;
    int count[5] = {0};
    int ans[5] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        switch (x % 5){
            case 0:
                if(x % 2 == 0) {
                    ans[0] += x;
                    count[0]++;
                }
                break;
            case 1:
                if(count[1] % 2 ==0) {
                    ans[1] += x;
                } else {
                    ans[1] -= x;  
                }
                count[1]++;
                break;
            case 2:
                count[2]++;
                ans[2]++;
                break;
            case 3:
                ans[3] += x;
                count[3]++;
                break;
            case 4:
                if(x > ans[4]){
                    ans[4] = x;
                }
                count[4]++;
                break;
            default:
                break;
        }
    }
    if(count[0] == 0) printf("N ");
    else printf("%d ", ans[0]);
    if(count[1] == 0) printf("N ");
    else printf("%d ", ans[1]);
    if(count[2] == 0) printf("N ");
    else printf("%d ", ans[2]);
    if(count[3] == 0) printf("N ");
    else printf("%.1f ", (double)ans[3] / count[3]);
    if(count[4] == 0) printf("N");
    else printf("%d", ans[4]);
    return 0;
}