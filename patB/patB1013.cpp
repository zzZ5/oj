#include<cstdio>
const int max = 1000001;
int prime[max], num = 0;
bool p[max] = {false};

void findPrime(int n) {
    for(int i = 2; i < max; i++){
        if(!p[i]){
            prime[num++] = i;
            if(num>n) break;
            for(int j = i + i; j < max; j += i){
                p[j] = true;
            }
        }
    }
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    findPrime(n);
    int count = 0;
    for(int i = m - 1; i < n; i++){
        printf("%d",prime[i]);
        count++;
        if(count % 10 == 0 || i == n-1){
            printf("\n");
        }else{
            printf(" ");
        }     
    }
    return 0;
}