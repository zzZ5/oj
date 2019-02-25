#include<cstdio>

//p进制转化为10进制，返回结果
int px2ten(int x,int p){
    int y=0,product=1;
    while(x!=0){
        y+=y%10*product;
        x=x/10;
        product*=p;
    }
    return y;
}

//10进制转化为p进制，返回结果储存在x数组中，返回数组长度
int ten2px(int y,int p,int x[]){
    int i=0;
    do{
        x[i++]=y%p;
        y=y/p;
    }while(y!=0);
    return i;
}

int main(){

    return 0;
}

