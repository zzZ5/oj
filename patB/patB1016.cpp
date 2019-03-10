#include <cstdio>
#include <cstring>

int main() {
    char A[20], B[20];
    char da, db;
    long long pa = 0, pb = 0;
    scanf("%s %c %s %c", A, &da, B, &db);
    int na = strlen(A), nb = strlen(B);
    for(int i = 0; i < na; i++) {
        if(A[i] == da){
            pa = pa * 10 + (da - '0');
        }
    }
    for(int i = 0; i < nb; i++) {
        if(B[i] == db){
            pb = pb * 10 + (db - '0');
        }
    }
    printf("%lld\n", pa + pb);
    return 0;
}