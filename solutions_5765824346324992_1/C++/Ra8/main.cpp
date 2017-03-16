#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
typedef long long ll;
using namespace std;
ll bbb[1010];
ll B,N;
set<pair<ll,ll> > s;
ll solve(){
    pair<ll,ll> mn;
    for(int i=0;i<B;i++){
        s.insert(make_pair(0,i));
    }
    for(ll turn=1;turn<N;turn++){
        if(turn%10000000==0)
        cout << turn << endl;
        mn=*s.begin();
        s.erase(s.begin());
        mn.first=mn.first+bbb[mn.second];
        s.insert(mn);
    }
    mn=*s.begin();
    return mn.second+1;
}
//int zx[1000000000];
ll cntt(ll minute){
    if(minute==-1)return 0;
    ll tot=0;
    for(int i=0;i<B;i++){
        tot=tot+minute/bbb[i]+1;
    }
    return tot;
}
ll solve2(){
    ll end=100000000000000000LL;
    ll endcnt=cntt(end);
    ll start=-1;
    ll startcnt=cntt(start);
    ll mid=0;
    ll midcnt;
    bool mmm=false;
    N--;
    while(start<end){
        mid=(start+end)/2;
        midcnt=cntt(mid);
        if(midcnt==N)break;
        if(midcnt<N){
            startcnt=midcnt;
            start=mid+1;
        } else{
            endcnt=midcnt;
            end=mid;
        }
        if(start==-1 && end==0){
            mid=-1;
            midcnt=0;
            break;
        }
    }
    N++;
    mid++;
    ll tmp=midcnt;
    ll i=0;
    //cout << start << " " << mid << endl;
    if(midcnt>=N && mid!=0){
        mid--;
        while(tmp==midcnt){
            mid--;
            midcnt=cntt(mid);
        }
        mid++;
    }
    //cout << mid << " " << midcnt << " " << N << endl;
    //return 0;
    N=N-midcnt;
    pair<ll,ll> mn;
    for(int i=0;i<B;i++){
        //cout << i << ": " << bbb[i] << " " << mid%bbb[i] << " "<< (bbb[i]-mid%bbb[i])%bbb[i] << endl;
        s.insert(make_pair((bbb[i]-mid%bbb[i])%bbb[i],i));
    }
    for(ll turn=1;turn<N;turn++){
        //if(turn%10000000==0)
        //cout << turn << endl;
        mn=*s.begin();
        s.erase(s.begin());
        mn.first=mn.first+bbb[mn.second];
        s.insert(mn);
    }
    mn=*s.begin();
    return mn.second+1;

    return 0;
}
int main()
{
    freopen("txt.in","r",stdin);
    freopen("out","w",stdout);
    ll T;
    cin >> T;
    for(ll t=0;t<T;t++){
        s.clear();
        cin >> B>> N;
        for(int i=0;i<B;i++){
            cin >> bbb[i];
        }
        //if(N<110000)
        //cout << "Case #" << (t+1) <<": "<< solve() << endl;
        //else
        cout << "Case #" << (t+1) <<": "<< solve2() << endl;
    }
    return 0;
}
