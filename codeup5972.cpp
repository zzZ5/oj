#include<cstdio>
const int maxn=11;
int n;
int visit[maxn];
bool hashTable[maxn]={false};

void DFS(int index){
    if(index==n){
        for(int i=0;i<n-1;i++){
            printf("%d ",visit[i]);
        }
        printf("%d\n",visit[n-1]);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!hashTable[i]){
            visit[index]=i;
            hashTable[i]=true;
            DFS(index+1);
            hashTable[i]=false;
        }
    }
}

int main(){
    scanf("%d",&n);
    DFS(0);
    return 0;
}