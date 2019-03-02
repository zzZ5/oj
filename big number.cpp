#include<cstdio>
#include<cstring>

struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};

bign change(char str[]){
    bign ret;
    ret.len=strlen(str);
    for(int i=0;i<ret.len;i++){
        ret.d[i]=str[ret.len-i-1]-'0';
    }
    return ret;
}

int compare(bign a,bign b){
    if(a.len>b.len){
        return 1;
    }else if(a.len<b.len){
        return -1;
    }else{
        for(int i=a.len-1;i>=0;i--){
            if(a.d[i]>b.d[i]){
                return 1;
            }else if(a.d[i]<b.d[i]){
                return -1;
            }
        }   
        return 0;
    }
}

bign add(bign a,bign b){
    bign ret;
    int carry=0;
    for(int i=0;i<a.len || i<b.len;i++){
        int temp=a.d[i]+b.d[i]+carry;
        ret.d[ret.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0){
        ret.d[ret.len++]=carry;
    }
    return ret;
}

bign sub(bign a,bign b){
    bign ret;
    for(int i=0;i<a.len || i<b.len;i++){
        if (a.d[i]<b.d[i]) {
            a.d[i+1]--;
            a.d[i]+=10;
        }
        ret.d[ret.len++]=a.d[i]-b.d[i];
    }

    while(ret.len>1 && ret.d[ret.len-1]==0){
        ret.len--;
    }
    return ret;
}

void  print(bign a){
    for(int i=a.len-1;i>=0;i--){
        printf("%d",a.d[i]);
    }
}

int main(){
    while(1){
        char a[20],b[20];
        scanf("%s%s",a,b);
        bign ba=change(a);
        bign bb=change(b);
        print(sub(ba,bb));
        printf("\n");
    }
    return 0;
}