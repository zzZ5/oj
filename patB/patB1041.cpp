#include <cstdio>
const int MAXN = 1001;

struct Student{
    long long id;
    int examSeat;
}testSeat[MAXN];

int main() {
    int n;
    long long id;
    int seat, examSeat;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld%d%d", &id, &seat, &examSeat);
        testSeat[seat].id = id;
        testSeat[seat].examSeat = examSeat;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &seat);
        printf("%lld %d\n", testSeat[seat].id, testSeat[seat].examSeat);
    }
    return 0;
}