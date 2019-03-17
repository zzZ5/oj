#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;

string marsDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string marsTen[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string num2Str[170];
map<string, int> str2Num;

void init() {
    for(int i = 0; i < 13; i++) {
        num2Str[i] = marsDigit[i];
        str2Num[marsDigit[i]] = i;
        num2Str[i * 13] = marsTen[i];
        str2Num[marsTen[i]] = i * 13;
    }
    for(int i = 1; i < 13; i++) {
        for(int j = 1; j < 13; j++) {
            string str = marsTen[i] + " " + marsDigit[j];
            num2Str[i * 13 + j] = str;
            str2Num[str] = i * 13 + j;
        }
    }
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9') {
            int num = 0;
            for(int i = 0; i < (int)str.length(); i++)
                num = num * 10 + (str[i] - '0');
            cout << num2Str[num] << endl;
        } else {
            cout << str2Num[str] << endl;
        }
    }
    return 0;
}