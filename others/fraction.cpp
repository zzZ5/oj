#include<cstdio>
#include<cmath>

typedef struct Fraction{
    int up,down;
}Fraction;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

Fraction reduction(Fraction result){
    if(result.down<0){
        result.up=-result.up;
        result.down=-result.down;
    }
    if(result.up==0){
        result.down=1;
    }else{
        int d=gcd(abs(result.up),abs(result.down));
        result.up/=d;
        result.down/=d;
    }
    return result;
}

Fraction add(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down+f1.down+f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}

Fraction minu(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down-f1.down+f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down;
    result.down=f1.down*f2.up;
    return reduction(result);
}

void showResult(Fraction result){
    result=reduction(result);
    if(result.down==1){
        printf("%d",result.up);
    }else if(abs(result.up)>result.down) {
        printf("%d %d/%d",result.up/result.down,abs(result.up%result.down),result.down);
    }else{
        printf("%d/%d",result.up,result.down);
    }
}

int main(){
    int a1,b1,a2,b2;
    scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
    Fraction c={
        .up=a1,
        .down=b1
    };
    Fraction d={
        .up=a2,
        .down=b2
    };
    c=add(c,d);
    showResult(c);
    return 0;
}