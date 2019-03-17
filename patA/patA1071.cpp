#include <map>
#include <iostream>
#include <string>
using namespace std;

map<string, int> hashTable;

bool check(char c) {
    if(c >= '0' && c <= '9') return true;
    else if(c >= 'A' && c <= 'Z') return true;
    else if(c>= 'a' && c<= 'z') return true;
    else return false;
}   

int main() {
    string str;
    getline(cin, str);
    int i = 0;
    while(i < (int)str.length()) {
        string word;
        while(check(str[i]) && i < (int)str.length()) {
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' +'a';
            word += str[i];
            i++;
        }
        if(word != "") {
            if(hashTable.find(word) != hashTable.end()) {
                hashTable[word]++;
            } else {
                hashTable[word] = 1;
            }
        }
        while(i < (int)str.length() && !check(str[i]))
            i++;
    }
    string ans;
    int maxNum = 0;
    for(map<string, int>::iterator it = hashTable.begin(); it != hashTable.end(); it++) {
        if(it->second > maxNum) {
            ans = it->first;
            maxNum = it->second;
        }
    }
    cout << ans << " " << maxNum << endl;
    return 0;
}