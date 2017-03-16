#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

struct Event{
    int b;
    LL m;
    Event(){}
    Event(int _b,LL _m):b(_b),m(_m){}
    bool operator<(const Event &e)const{
        return m == e.m ? b > e.b : m > e.m;
    }
};

bool check(const vector<int> &M, const int N, const LL thres){
    LL n = 0;
    REP(i,M.size()){
        n += thres/M[i] + 1;
    }
    return n < N;
}

LL solve(const vector<int> &M, const int N){
    LL lb = 0, ub = 1000000000000000000LL;
    while(ub-lb>1){
        LL mid = (lb+ub)/2LL;
        if(check(M,N,mid))lb = mid;
        else ub = mid;

    }
    //cout << lb << endl;

    priority_queue<Event> que;

    LL cnt = 0;
    REP(i,M.size()){
        LL d = lb/M[i];
        cnt += d;
        que.push(Event(i, d*M[i]));
    }
    //cout << cnt << " " << N << " " << lb << endl;
    Event e = Event(-100, 0);
    for(;cnt < N; cnt++){
        e = que.top();
        //cout << e.b << " " << e.m << endl;
        que.pop();
        que.push(Event(e.b,e.m + M[e.b]));
    }
    return e.b + 1;
}

int main(){
    int T;
    cin >> T;

    REP(i, T){
        int B, N;
        cin >> B >> N;
        vector<int> M(B);
        REP(j,B)cin >> M[j];
        LL ans = solve(M, N);
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}
