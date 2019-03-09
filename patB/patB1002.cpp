#include <cstring>
#include <cstdio>

int main() {
    char str[110];
    scanf("%s", str);
    int sum = 0;
    for(int i = 0; i < strlen(str); i++) {
        sum += str[i] - '0';
    }
    char ans[10]; 
    sprintf(ans,"%d", sum);
    for(int i = 0; i < strlen(ans); i++) {
        switch (ans[i])
        {
            case '0':
                printf("ling");
                break;
            case '1':
                printf("yi");;
                break;
            case '2':
                printf("er");
                break;
            case '3':
                printf("san");
                break;
            case '4':
                printf("si");
                break;
            case '5':
                printf("wu");
                break;
            case '6':
                printf("liu");
                break;
            case '7':
                printf("qi");
                break;
            case '8':
                printf("ba");
                break;
            case '9':
                printf("jiu");
                break;
            default:
                break;
        }
        if(i < strlen(ans)-1){
            printf(" ");
        }
    }
    return 0;
}