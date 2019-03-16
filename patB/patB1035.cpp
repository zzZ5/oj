#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 101;

int origin[N], tempOri[N], changed[N];
int n;

bool isSame(int a[], int b[]){
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

bool printArray(int a[]) {
    for(int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if(i < n - 1) printf(" ");
    }
    printf("\n");
}

bool insertSort() {
    bool flag = false;
    for(int i = 1; i < n; i++) {
        if(i != 1 && isSame(tempOri, changed)) flag = true;
        int temp = tempOri[i], j = i;
        for(; j > 0; j--) {
            if(temp < tempOri[j - 1]) tempOri[j] = tempOri[j - 1];
            else break;
        }
        tempOri[j] = temp;
        if(flag) return flag;
    }
    return false;
}

void mergeSort() {
    bool flag = false;
    for(int step = 2; step / 2 <= n; step *= 2) {
        if(step != 2 && isSame(tempOri, changed)) flag = true;
        for(int i = 0; i < n; i += step) {
            sort(tempOri + i, tempOri + min(i + step, n));
        }
        if(flag){
            printArray(tempOri);
            return;
        }
    }

}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
        tempOri[i] = origin[i];
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &changed[i]);
    }
    if(insertSort()) {
        printf("Insertion Sort\n");
        printArray(tempOri);
    } else {
        printf("Merge Sort\n");
        for(int i = 0; i < n; i++) {
            tempOri[i] = origin[i];
        }
        mergeSort();
    }
    return 0;
}