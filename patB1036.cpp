#include<cstdio>
int main(){
    int row,col;
    char  c;
    scanf("%d %c",&col,&c);
    if(col%2!=0){
        row=col/2+1;
    }else{
        row=col/2;
    }

    for(int i=0;i<col;i++){
        printf("%c",c);
    }
    printf("\n");
    for(int i=2;i<row;i++){
        printf("%c",c);
        for(int i=2;i<col;i++){
            printf(" ");
        }
        printf("%c",c);
        printf("\n");
    }
    for(int i=0;i<col;i++){
        printf("%c",c);
    }
    return 0;
}