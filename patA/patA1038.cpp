#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10001;

bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    int n;
    string str[MAXN];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string ans;
    for(int i = 0; i < n; i++) {
        ans += str[i];
    }
    while(ans.length() > 1 && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    cout << ans << endl;
    return 0;
}