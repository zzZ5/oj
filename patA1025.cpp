#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct student
{
    char id[15];
    int score;
    int tl;//testLocation
    int lr;//localRank
}stus[30000];//students

bool cmp(student a,student b){
    if(a.score!=b.score)
        return a.score>b.score;
    else
        return strcmp(a.id,b.id)<0;
}

int main(){
    int n,ln;//总人数和单个考场人数
    int num=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ln);
        for(int j=0;j<ln;j++){
            scanf("%s %d",stus[num].id,&stus[num].score);
            stus[num].tl=i;
            num++;
        }
        sort(stus+num-ln,stus+num,cmp);
        stus[num-ln].lr=1;
        for(int k=num-ln+1;k<num;k++){
            if(stus[k].score==stus[k-1].score){
                stus[k].lr=stus[k-1].lr;
            }else
            {
                stus[k].lr=k-num+ln+1;
            }
        }
    }

    printf("%d\n",num);
    sort(stus,stus+num,cmp);
    int rank=1;
    printf("%s %d %d %d\n",stus[0].id,rank,stus[0].tl,stus[0].lr);
    for(int i=1;i<num;i++){
        if(stus[i].score!=stus[i-1].score){
            rank=i+1;
        }
        printf("%s %d %d %d\n",stus[i].id,rank,stus[i].tl,stus[i].lr);
    }
    return 0;
}