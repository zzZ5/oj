#include<cstdio>

int ten2px(int y,int p,int *x){
    int i=0;
    do{
        x[i++]=y%p;
        y=y/p;
    }while(y!=0);
    return i;
}

int main(){
    int a,b,p;
    scanf("%d%d%d",&a,&b,&p);
    int ans[31];
    int n=ten2px(a+b,p,ans);
    for(int i=n-1;i>=0;i--){
        printf("%d",ans[i]);
    }
    return 0;
}