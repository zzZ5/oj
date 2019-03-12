#include <cstdio>

int main() {
    int index;
    double ans = 1.0, maxPro, temp;
    char S[3] = {'W', 'T', 'L'};
    for(int i = 0; i < 3; i++) {
        maxPro = 0.0;
        for(int j = 0; j < 3; j++) {
            scanf("%lf", &temp);
            if(temp > maxPro) {
                maxPro = temp;
                index = j;
            }
        }
        ans *= maxPro;
        printf("%c ", S[index]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}