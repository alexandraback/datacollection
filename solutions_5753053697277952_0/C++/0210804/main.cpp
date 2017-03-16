#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

class Party{
public:
    char name;
    int num;
    bool operator<(const Party &rhs)const{
        return num<rhs.num;
    }
};

priority_queue<Party> pq;
void solve(){

    int n;
    scanf("%d",&n);
    int total = 0;
    for(int i=0;i<n;i++){
        Party p;
        p.name = 'A'+i;
        scanf("%d",&p.num);
        total += p.num;
        pq.push(p);
    }

    while(!pq.empty()){
        Party discuss = pq.top();
        pq.pop();
        printf(" %c",discuss.name);
        total--;
        if(!pq.empty()&&pq.top().num*2>total){
            Party another = pq.top();
            pq.pop();
            printf("%c",another);
            total--;
            if(--another.num>0){
                pq.push(another);
            }
        }
        if(--discuss.num>0){
            pq.push(discuss);
        }
    }
    puts("");
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("small_a.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d:",i);
        solve();
    }
    return 0;
}
