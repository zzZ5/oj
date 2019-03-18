#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 101;

int origin[MAXN], tempOri[MAXN], changed[MAXN], n;

bool isSame(int a[], int b[]){
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

void printArray(int a[]) {
    for(int i = 1; i <= n; i++) {
        printf("%d", a[i]);
        if(i < n) printf(" ");
    }
    printf("\n");
}

bool insertSort() {
    bool flag = false;
    for(int i = 2; i <= n; i++) {
        if(i != 2 && isSame(tempOri, changed)) flag = true;
        int temp = tempOri[i], j = i;
        for(; j > 1; j--) {
            if(temp < tempOri[j - 1]) tempOri[j] = tempOri[j - 1];
            else break;
        }
        tempOri[j] = temp;
        if(flag) return flag;
    }
    return false;
}


void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while(j <= high) {
        if(j + 1 <= high && tempOri[j+1] > tempOri[j]) {
            j = j + 1;
        }
        if(tempOri[j] > tempOri[i]){
            swap(tempOri[j], tempOri[i]);
            i = j;
            j = i * 2;
        } else break;
    }
}

void heapSort() {
    bool flag = false;
    for(int i = n / 2; i > 0; i--)
        downAdjust(i, n);
    for(int i = n; i > 1; i--) {
        if(i != n && isSame(tempOri, changed)) flag = true;
        swap(tempOri[1], tempOri[i]);
        downAdjust(1, i - 1);
        if(flag) {
            printArray(tempOri);
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &origin[i]);
        tempOri[i] = origin[i];
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &changed[i]);
    }
    if(insertSort()) {
        printf("Insertion Sort\n");
        printArray(tempOri);
    } else {
        printf("Heap Sort\n");
        for(int i = 1; i <= n; i++) {
            tempOri[i] = origin[i];
        }
        heapSort();
    }
    return 0;
}