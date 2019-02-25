#include<cstdio>
const int max=100000;
int school[max]={0};
int main(){
    int n,id,score;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&id,&score);
        school[id]+=score;
    }
    int k=1,maxScore=-1;
    for(int i=1;i<=n;i++){
        if(school[i]>maxScore){
            k=i;
            maxScore=school[i];
        }
    }
    printf("%d %d",k,maxScore);
    return 0;
}