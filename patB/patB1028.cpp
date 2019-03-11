#include <cstdio>

struct People{
    char name[10];
    int yy, mm, dd;
}oldest, youngest, left, right, temp;

int compare(People a, People b) {
    if(a.yy != b.yy){
        return a.yy - b.yy;
    } else if(a.mm != b.mm) {
        return a.mm - b.mm;
    } else if(a.dd != b.dd) {
        return a.dd - b.dd;
    }
}

bool judge() {
    bool ret = true;
    if(compare(temp, right) > 0) {
        ret = false;
    }
    if(compare(temp, left) < 0) {
        ret = false;
    }
    return ret;
}

void init() {
    left.yy = youngest.yy = 1814;
    right.yy = oldest.yy = 2014;
    left.mm = right.mm = youngest.mm = oldest.mm = 9;
    right.dd = left.dd = youngest.dd = oldest.dd = 6;
}

int main() {
    int n, count = 0;
    scanf("%d", &n);
    init();
    for(int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d",&temp.name, &temp.yy, &temp.mm, &temp.dd);
        if(judge()){
            count++;
            if(compare(temp, youngest) > 0) {
                youngest = temp;
            }
            if(compare(temp, oldest) < 0) {
                oldest = temp;
            }
        }
    }
    if(count == 0) {
        printf("0\n");
    } else {
        printf("%d %s %s\n", count, oldest.name, youngest.name);
    }
    return 0;
}