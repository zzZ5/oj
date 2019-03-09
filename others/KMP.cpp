#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1001;

string str;
int len;
string subStr;
int subLen;
int next[MAXN];

void getNext() {
    int j = -1;
    next[0] = -1;
    for(int i = 1; i < len; i++) {
        while(j != -1 && str[i] != str[j + 1]) {
            j = next[j];
        }
        if(str[i] == str[j + 1]) {
            j++;
        }
        next[i] = j;
    }
}

void getNextval() {
    int j = -1;
    next[0] = -1;
    for(int i = 1; i < len; i++) {
        while(j != -1 && str[i] != str[j + 1]) {
            j = next[j];
        }
        if(str[i] == str[j + 1]) {
            j++;
        }
        if(j == -1 || str[i + 1] != str[j + 1]) {
            next[i] = j; 
        } else {
            next[i] = next[j];
        }
    }
}

int KMP() {
    getNext();
    int ans = 0, j = -1;
    for(int i = 0; i < len; i++) {
        while(j != -1 && str[i] != subStr[j +1]) {
            j = next[j];
        }
        if(str[i] == subStr[j +1]) {
            j++;
        }
        if(j == subLen - 1) {
            ans++;
            j = next[j];
        }
    }
    return ans;
}

int main() {
    getline(cin, str);
    getline(cin, subStr);
    len = str.length();
    subLen = subStr.length();
    int ans = KMP();
    return 0;
}