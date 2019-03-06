#include <iostream>
#include <map>
#include <string>
#include<queue>

using namespace std;
const int MAX = 2000;
const int INF = 1000000000;

map<int, string> int2string;
map<string, int> string2int;
map<string, int> Gang;

int G[MAX][MAX] = {0}, weight[MAX] = {0};
int edgeNum = 0, k, personNum = 0;
bool visit[MAX] = {false};

// void BFS(int nowVisit, int &head, int &memberNum, int &totalValue) {
//     memberNum++;
//     visit[nowVisit] = true;
//     if(weight[nowVisit] > weight[head]) {
//         head = nowVisit;
//     }
//     queue<int> q;
//     q.push(nowVisit);
//     while(!q.empty()) {
//         nowVisit = q.front();
//         q.pop();
//         for(int i = 0; i < personNum; i++) {
//             if(G[nowVisit][i] > 0) {
//                 totalValue += G[nowVisit][i];
//                 if(!visit[i]) {
//                     memberNum++;
//                     q.push(i);
//                     visit[i] = true;
//                 }
//              }
//         }
//     }
// }


void DFS(int nowVisit, int &head, int &memberNum, int &totalValue) {
    memberNum++;
    visit[nowVisit] = true;
    if(weight[nowVisit] > weight[head]) {
        head = nowVisit;
    }
    for(int i = 0; i < personNum; i++) {
        if(G[nowVisit][i] > 0) {
            totalValue += G[nowVisit][i];
            if(!visit[i]) {
                DFS(i, head, memberNum, totalValue);
            }
        }
    }
}

void Traver() {
    for(int i = 0; i < personNum; i++) {
        if(!visit[i]) {
            int head = i, memberNum = 0, totalValue = 0;
            DFS(i, head, memberNum, totalValue);
            // BFS(i, head, memberNum, totalValue);
            if(memberNum > 2 && totalValue > k) {
                Gang[int2string[head]] = memberNum;
            }
        }
    }
}

int change(string str) {
    if(string2int.find(str) != string2int.end()) {
        return string2int[str]; 
    } else {
        string2int[str] = personNum;
        int2string[personNum] = str;
        return personNum++;
    }
}

int main() {
    int w;
    string str1, str2;
    cin >> edgeNum >> k;
    for(int i = 0; i < edgeNum; i++) {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] +=w;
    }
    Traver();
    cout << Gang.size() << endl;
    for(map<string, int>::iterator it = Gang.begin(); it != Gang.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}