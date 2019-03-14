#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int MAXN = 10001;

struct Car{
    char id[8];
    int time;
    char status[4];
}all[MAXN], valid[MAXN];

bool cmpByIdAndTime(Car a, Car b) {
    if(strcmp(a.id, b.id) != 0) {
        return strcmp(a.id, b.id) < 0;
    } else {
        return a.time < b.time;
    }
}

bool cmpByTime(Car a, Car b) {
    return a.time < b.time;
}

int validNum = 0;
map<string, int> parkTime;

int time2Int(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}

int main() {
    int n, query, hh, mm, ss;
    scanf("%d%d", &n, &query);
    for(int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
        all[i].time = time2Int(hh, mm, ss);
    }
    sort(all, all + n, cmpByIdAndTime);
    int maxTime = -1;
    for(int i = 0; i < n - 1; i++) {
        if(!strcmp(all[i].id, all[i + 1].id) && !strcmp(all[i].status, "in") && !strcmp(all[i + 1].status, "out")) {
            valid[validNum++] = all[i];
            valid[validNum++] = all[i + 1];
            int thisTime = all[i + 1].time - all[i].time;
            if(!parkTime.count(all[i].id)) {
                parkTime[all[i].id] = 0;
            }
            parkTime[all[i].id] += thisTime;
            maxTime = max(parkTime[all[i].id], maxTime);
        }
    }
    sort(valid, valid + validNum, cmpByTime);
    int now = 0, numCar = 0;
    for(int i = 0; i < query; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = time2Int(hh, mm, ss);
        while(now < validNum && valid[now].time <= time) {
            if(!strcmp(valid[now].status, "in")) {
                numCar++;
            } else {
                numCar--;
            }
            now++;
        }
        printf("%d\n", numCar);
    }
    for(map<string, int>::iterator it = parkTime.begin(); it != parkTime.end(); it++) {
        if(it->second == maxTime) {
            printf("%s ", it->first.c_str());
        }
    }
    printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
    return 0;
}