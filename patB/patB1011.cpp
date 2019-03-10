#include <cstdio>
#include <cstring>
struct bign {
    int d[100];
    int len;
    bool isPositive;
    bign() {
        memset(d,0,sizeof(d));
        len = 0;
        isPositive = true;
    }
};

bign change(char str[]) {
    bign ret;
    int len = strlen(str);
    ret.len = len;
    if(str[0] == '-') {
        ret.isPositive = false;
        ret.len = ret.len - 1;
    }
    for(int i = 0; i < ret.len; i++){
        ret.d[i] = str[len - i - 1] - '0';
    }
    return ret;
}

int compare(bign a,bign b) {
    if(a.isPositive && !b.isPositive) {
        return 1;
    }
    if(!a.isPositive && b.isPositive) {
        return -1;
    }
    if(!a.isPositive && !b.isPositive) {
        a.isPositive = true;
        b.isPositive = true;
        return compare(b, a);
    }
    if(a.len>b.len) {
        return 1;
    }else if(a.len < b.len) {
        return -1;
    } else {
        for(int i = a.len-1; i >= 0; i--) {
            if(a.d[i] > b.d[i]) {
                return 1;
            } else if(a.d[i] < b.d[i]) {
                return -1;
            }
        }   
        return 0;
    }
}

bign sub(bign a,bign b) {
    bign ret;
    for(int i = 0; i < a.len || i < b.len; i++){
        if (a.d[i] < b.d[i]) {
            a.d[i+1]--;
            a.d[i] += 10;
        }
        ret.d[ret.len++] = a.d[i] - b.d[i];
    }

    while(ret.len>1 && ret.d[ret.len-1] == 0){
        ret.len--;
    }
    return ret;
}

bign add(bign a,bign b) {
    bign ret;
    if(a.isPositive && !b.isPositive){
        b.isPositive = true;
        if(compare(a, b) >= 0){
            return(sub(a, b));
        }else {
            ret = sub(b, a);
            ret.isPositive = false;
            return ret;
        }
    }
    if(!a.isPositive && b.isPositive){
        a.isPositive = true;
        if(compare(a, b) <= 0){
            return(sub(b, a));
        }else {
            ret = sub(a, b);
            ret.isPositive = false;
            return ret;
        }
    }
    if(!a.isPositive && !b.isPositive){
        a.isPositive = true;
        b.isPositive = true;
        ret = add(a, b);
        ret.isPositive = false;
        return ret;
    }
    int carry = 0;
    for(int i = 0; i < a.len || i < b.len; i++){
        int temp = a.d[i] + b.d[i] + carry;
        ret.d[ret.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0) {
        ret.d[ret.len++] = carry;
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    int tcase = 1;
    while(n-- > 0){
        char a[50], b[50], c[50];
        scanf("%s%s%s", a, b, c);
        bign ba = change(a);
        bign bb = change(b);
        bign bc = change(c);
        printf("Case #%d: ", tcase++);
        if(compare(add(ba,bb), bc) > 0){
            printf("true\n");
        } else {
            printf("false\n");            
        }
    }
    return 0;
}