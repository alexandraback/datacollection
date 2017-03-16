#include<iostream>
#include<vector>
#include<map>
#include<cstdlib>
#include<cstdint>
#include<queue>
using namespace std;
vector<int64_t> b;
int n,m;
int64_t calc(int64_t mid) {
    if(mid==0) return 0;
    int64_t sum = 0;
    for(int i=0;i<m;i++) sum += (int64_t)((mid-0.1) / b[i])+1;
    return sum;
}
struct barber {
    int i;
    int64_t time;
    barber(int a, int64_t b) {
        i=a;
        time=b;
    }
    bool operator <(const barber& b) const {
        if(time == b.time) return i > b.i;
        return time > b.time;
    }
};
int g(int64_t time) {
    priority_queue<barber> q;
    int num = calc(time);
//    cout<<"Ajassa "<<time<<" "<<num<<" ihmistä istumassa\n";
    for(int i=0;i<m;i++) {
        q.push( barber(i,(int64_t)((time - 0.1)/b[i]+1)*b[i]));
    }
    while(num < n) {
        barber br = q.top();
       // cout<<"Ajassa "<<br.time<<" tyyppi numero "<<(num+1)<<" istuu paikalle "<<(br.i+1)<<endl
     //       cout<<"Ajassa "<<br.time<<" tyyppi numero "<<(num+1)<<" istuu paikalle "<<(br.i+1)<<endl;;
        q.pop();
        num++;
        q.push(barber(br.i, br.time + b[br.i]));
    }
    return  q.top().i+1;
}
int f() {
    cin>>m>>n;
    b.resize(m);
    for(int i=0;i<m;i++) cin>>b[i];
    if(n <= m) return n;
    n--;
    int64_t low=0,high=1LL<<60;;
    while(high-low>2) {
        int64_t mid = (high+low)/2;
        int64_t sum = calc(mid);
        if(sum >= n) high = mid;
        else low= mid;
    }
    return g(max(0L,low));
}
int main() {
    int T;
    cin>>T;
    for(int i=1;i<=T;i++) {
        cout<<"Case #"<<i<<": "<<f()<<"\n";
    }
}
