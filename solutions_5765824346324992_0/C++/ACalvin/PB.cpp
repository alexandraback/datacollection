#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a % b);
}
int M[100];
struct Node{
    int id,time;
    Node(){}
    Node(int id,int time):id(id),time(time){}
    bool operator < (const Node &a)const{
        if(time != a.time) return time > a.time;
        return id > a.id;
    }
};
priority_queue<Node> Q;
int txt = 1;
void solve(){
    while(!Q.empty()) Q.pop();
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i = 1 ; i <= n ; i ++) scanf("%d",&M[i]);
    int LCM = 1;
    for(int i = 1 ; i <= n ; i ++){
        LCM = LCM * M[i] / gcd(LCM,M[i]);
    }
    int cnt = 0;
    for(int i = 1 ; i <= n ; i ++){
        cnt += LCM / M[i];
    }
    l %= cnt;
    if(!l) l += cnt;
    int ans;
    for(int i = 1 ; i <= n ; i ++) Q.push(Node(i,0));
    while(l --){
        Node u = Q.top();Q.pop();
        ans = u.id;
        u.time += M[u.id];
        Q.push(u);
    }
    printf("Case #%d: %d\n",txt ++,ans);
}
int main()
{
    freopen("dataPB.in","r",stdin);
    freopen("dataPB.out","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
