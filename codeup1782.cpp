#include<cstdio>

int main(){
    
    int n,m,index,k;
    while(scanf("%d%d",&n,&m)!=EOF){
        int books[201]={0};
        int *students=new int[n];
        for(int i=0;i<n;i++){
            scanf("%d",&index);
            books[index]++;
            students[i]=index;
        }
        for(int i=0;i<n;i++){
            k=books[students[i]];
            if(k>1){
                printf("%d\n",k-1);
            }else
            {
                printf("BeiJu\n");
            }
        }
        delete(students);
    }
    return 0;
}