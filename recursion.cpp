#include<cstdio>

const int max=11;
bool hashTable[max]={false};
int n,p[max];
void generateP(int index){
    if(index==n+1){
        for(int i=1;i<=n;i++){
            printf("%d",p[i]);
        }
        printf("\n");
        return;
    }
    for(int x=1;x<=9;x++){
        if(hashTable[x]==false){
            p[index]=x;
            hashTable[x]=true;
            generateP(index+1);
            hashTable[x]=false;
        }
    }
}

int main(){
    n=3;
    generateP(1);    
    return 0;
}