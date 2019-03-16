#include<cstdio>
#include<math.h>
typedef long long LL;

struct Fraction {
    LL up, down;
};

int gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
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
    if(result.up < 0) printf("(");
    if(result.down == 1) printf("%lld", result.up);
    else if(abs(result.up) > result.down) 
    printf("%lld %lld/%lld", result.up/result.down, (LL)abs(result.up) % result.down, result.down);
    else printf("%lld/%lld",result.up, result.down);
    if(result.up < 0) printf(")");
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
    Fraction f1;
    Fraction f2;
    scanf("%lld/%lld",&f1.up, &f1.down);
    scanf("%lld/%lld",&f2.up, &f2.down);
    
    showResult(f1);
    printf(" + ");
    showResult(f2);
    printf(" = ");
    showResult(add(f1, f2));
    printf("\n");

    showResult(f1);
    printf(" - ");
    showResult(f2);
    printf(" = ");
    showResult(minu(f1, f2));
    printf("\n");

    showResult(f1);
    printf(" * ");
    showResult(f2);
    printf(" = ");
    showResult(multi(f1, f2));
    printf("\n");

    showResult(f1);
    printf(" / ");
    showResult(f2);
    printf(" = ");
    if(f2.up == 0) printf("Inf");
    else showResult(divide(f1, f2));

    return 0;
}