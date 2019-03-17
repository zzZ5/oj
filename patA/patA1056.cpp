#include <cstdio>
#include <queue>
using namespace std;
const int N = 1001;

struct Mouse {
    int weight;
    int Rank;
}mouse[N];

int main() {
    int np, ng, order;
    scanf("%d%d", &np, &ng);
    for(int i = 0; i < np; i++) {
        scanf("%d", &mouse[i].weight);
    }
    queue<int> q;
    for(int i = 0; i < np; i++) {
        scanf("%d", &order);
        q.push(order);
    }
    int temp = np, group;
    while(q.size() != 1) {
        group = (temp + ng - 1) / ng;
        for(int i = 0; i < group; i++) {
            int k =q.front();
            for(int j = 0; j < ng; j++) {
                if(i * ng + j >= temp) break;
                int front = q.front();
                if(mouse[front].weight > mouse[k].weight) {
                    k = front;
                }
                mouse[front].Rank = group + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    mouse[q.front()].Rank = 1;
    for(int i = 0; i < np; i++) {
        printf("%d", mouse[i].Rank);
        if(i< np - 1) printf(" ");
    }
    return 0;
}