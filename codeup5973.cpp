#include<cstdio>
const int maxn=22;
int n;
int r;
int visit[maxn];

void DFS(int index){
    if(index==r){
        for(int i=0;i<r-1;i++){
            printf("%d ",visit[i]);
        }
        printf("%d\n",visit[r-1]);
        return;
    }
    for(int i=(index?visit[index-1]+1:1);i<=n;i++){
        visit[index]=i;
        DFS(index+1);
    }
}

int main(){
    scanf("%d%d",&n,&r);
    DFS(0);
    return 0;
}