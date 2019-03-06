#include<cstdio>
#include<cstring>
const int MAX=100000;
const int MOD=1000000007;
char str[MAX];
int leftP[MAX]={0};
int rightT[MAX]={0};


int main(){
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(i>0){
            leftP[i]=leftP[i-1];
            rightT[len-i-1]=rightT[len-i];
        }
        if(str[i]=='P'){
            leftP[i]++;
        }
        if(str[len-i-1]=='T'){
            rightT[len-i-1]++;
        }
    }
    int ans=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='A'){
            ans=(ans+leftP[i]*rightT[i])%MOD;
        }
    }
    printf("%d",ans);
    return 0;
}