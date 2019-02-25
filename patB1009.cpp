#include<cstdio>
#include<cstring>

int main(){
    char ans[90][90];
    int i=0;
    while(scanf("%s",ans[i])!=EOF){
        i++;
    }
    for(int j=i-1;j>=0;j--){
        printf("%s",ans[j]);
        if(j>0){
            printf(" ");
        }
    }
    return 0;
}

//oj中gets函数禁止使用

// int main(){
//     char str[90];
//     gets(str);
//     char ans[90][90];
//     int row,col=0;
//     int n=strlen(str);
//     for(int i=0;i<n;i++){
//         if (str[i]!=' ') {
//             ans[row][col++]=str[i];
//         }else
//         {
//             ans[row][col]='\0';
//             row++;
//             col=0;
//         }
//     }
//     for(int i=row;i>=0;i--){
//         printf("%s",ans[i]);
//         if(i>0){
//             printf(" ");
//         }
//     }
//     return 0;
// }




