#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define mem(a) memset(a,0,sizeof(a))
#define pd(a) printf("%.10f\n",a)
#define pb(a) push_back(a)
#define in(a) insert(a)
#define pi M_PI
#define R cin>>
#define F first
#define S second
#define C class
#define ll long long
#define ln cout<<'\n'
#define _(_1,_2,_3,N,...)N
#define pr(...) _(__VA_ARGS__,pr3,pr2,pr1)(__VA_ARGS__)
template<C T>void pr1(T a){cout<<a;ln;}
template<C T,C T2>void pr2(T a,T2 b){cout<<a<<' '<<b;ln;}
template<C T,C T2,C T3>void pr3(T a,T2 b,T3 c){cout<<a<<' '<<b<<' '<<c;ln;}
template<C T>void PR(T a,int n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;

void Main() {
  int T;
  R T;
  REP(tt,1,T+1) {
    int n;
    R n;
    int sum=0;
    P a[n];
    rep(i,n) {
      R a[i].F;
      a[i].S=i;
      sum+=a[i].F;
    }
    sort(a,a+n,greater<P>());
    vector<string> v;
    a[n-2].F-=a[n-1].F;
    priority_queue<P> que;
    rep(i,n-1) if(a[i].F) que.push(a[i]);
    while(!que.empty()) {
      P p=que.top();que.pop();
      string s="";
      s+=p.S+'A';
      p.F--;
      sum--;
      if(p.F) {
        s+=p.S+'A';
        p.F--;
        sum--;
        if(!que.empty()) {
          P q=que.top();que.pop();
          if(q.F+(q.S==a[n-2].S?a[n-1].F:0)>sum/2) {
            s[1]=q.S+'A';
            p.F++;
            q.F--;
          }
          if(q.F) que.push(q);
        }
      } else if(!que.empty()){
        P q=que.top();que.pop();
        if(q.F+(q.S==a[n-2].S?a[n-1].F:0)>sum/2) {
          s+=q.S+'A';
          q.F--;
        }
        if(q.F) que.push(q);
      }
      if(p.F) que.push(p);
      v.pb(s);
    }
    rep(i,a[n-1].F) {
      string s="";
      s+=a[n-2].S+'A';
      s+=a[n-1].S+'A';
      v.pb(s);
    }
    cout << "Case #" << tt << ": ";
    PR(v,v.size());
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  Main();return 0;
}
