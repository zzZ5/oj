#include<stdio.h>
int main(){
    int n,step=0;
    scanf("%d",&n);
    while(n!=1){
        step++;
        if(n%2==0)
            n/=2;
        else
            n=(n*3+1)/2;
    }
    printf("%d",step);
    return 0;
}