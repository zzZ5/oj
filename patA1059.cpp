#include<cstdio>
#include<cmath>

const int MAX=100010;
int prime[MAX],pNum=0;

struct factor{
   int x,cnt;
}fac[10];

bool isPrime(int n){
    bool flag=(n==1?false:true);
    int sqr=(int)sqrt(1.0*n);
    for(int i=2;i<=sqr;i++){
        if(n%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}

void findPrime(){
    for(int i=1;i<MAX;i++){
        if(isPrime(i)){
            prime[pNum++]=i;
        }
    }
}

int main(){
    findPrime();
    int n,num;
    scanf("%d",&n);
    if(n==1){
     printf("1=1");
    }    
    else {
        printf("%d=",n);
        int sqr=(int)sqrt(1.0*n);
        for(int i=0;i<pNum && prime[i]<=sqr;i++){
            if(n%prime[i]==0){
                fac[num].x=prime[i];
                fac[num].cnt=0;
                while(n%prime[i]==0){
                    n/=prime[i];
                    fac[num].cnt++;
                }
                num++;
            }
            if (n==1) {
                break;
            }
        }
    }
    if(n!=1){
        fac[num].x=n;
        fac[num++].cnt=1;
    }
    for(int i=0;i<num;i++){
        if(i>0){
            printf("*");
        }
        printf("%d",fac[i].x);
        if(fac[i].cnt>1){
            printf("^%d",fac[i].cnt);
        }
    }
    return 0;
}