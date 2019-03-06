#include<cstdio>

int n,count,p[16];

bool legal(int a,int b){//判断两点是否合法
    bool flag=true;
    if(a%n==b%n){
        flag=false;
        for(int i=a+n;i<b;i+=n){
            if(p[i]==2){
                flag=true;
            }
        }
    }else if(a/n==b/n)
    {
        flag=false;
        for(int i=a+1;i<b;i++){
            if(p[i]==2){
                flag=true;
            }
        }
    }
    return flag;
}

void judge(int index){
    for(int x=0;x<n*n;x++){
        if (p[x]==0) {
            bool flag=true;
            for(int pre=0;pre<n*n;pre++){
                if(p[pre]==1){
                    if(!legal(pre,x)){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                p[x]=1;
                judge(index+1);
                p[x]=0;
            }
        }    
    }
    count=(count>index?count:index);
}


int main(){
    scanf("%d",&n);
    while(n>0){
        for(int i=0;i<n*n;i++){
            char temp;
            scanf(" %c",&temp);
            if(temp=='.'){
                p[i]=0;
            }else
            {
                p[i]=2;
            }
        }
        count=0;
        judge(0);
        printf("%d\n",count);
        scanf("%d",&n);
    }
    return 0;
}