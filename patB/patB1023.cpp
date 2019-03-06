#include<cstdio>

int main(){
    int num[10]={0};
    for(int i=0;i<10;i++){
        scanf("%d",&num[i]);
    }
    for(int j=1;j<10;j++){
        if(num[j]>0){
            printf("%d",j);
            num[j]--;
            break;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<num[i];j++){
            printf("%d",i);
        }
    }
    return 0;
}