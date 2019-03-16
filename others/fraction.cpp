#include<cstdio>
#include<math.h>
typedef long long LL;

struct Fraction {
    LL up, down;
};

int gcd(int a,int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

Fraction reduction(Fraction result) {
    if(result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0) result.down = 1;
    else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

void showResult(Fraction result) {
    result = reduction(result);
    if(result.down == 1) printf("%lld", result.up);
    else if(abs(result.up) > result.down) 
    printf("%lld %lld/%lld\n", result.up/result.down, (LL)abs(result.up) % result.down, result.down);
    else printf("%lld/%lld\n",result.up, result.down);
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f1.down * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}


Fraction minu(Fraction f1,Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f1.down * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

int main() {
    int n;
    scanf("%d", &n);
    Fraction ans = {
        .up = 0,
        .down = 1
    };
    Fraction temp;
    for(int i = 0; i < n; i++) {
        scanf("%lld/%lld",&temp.up, &temp.down);
        ans = add(ans, temp);
    }
    showResult(ans);
    return 0;
}