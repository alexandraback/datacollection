#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cstdarg>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#define ll long long int
#define pb push_back
#define fr(i,n)     for(int i=0;i<n;i++)
#define init(mem,v) memset(mem,v,sizeof(mem))
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#if __cplusplus > 199711L
    void read(){}
    template<typename... T>
    void read(int& head, T&... tail) {scanf("%d",&head); read(tail...);}

    #define DB(args...) { cerr << __LINE__<< ": "; vector<string> _v = split(#args, ','); err(_v.begin(), args); }
    vector<string> split(const string& s, char c) {
        vector<string> v;stringstream ss(s);string x;
        while (getline(ss, x, c)) v.push_back(x);
        return move(v);
    }
    void err(vector<string>::iterator it) {cerr<<endl;}
    template<typename T, typename... Args>
    void err(vector<string>::iterator it, T a, Args... args) {
        cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << "  "; err(++it, args...);
    }
#else
    #define DB(args...)
    void read(int& head) {scanf("%d",&head);}
#endif

#define mx 1005
ll M[mx];

ll ceil(ll a,ll b){
    if(a%b==0) return a/b;
    else return 1+a/b;
}

int main(){
    int t;
    read(t);
    fr(ii,t){
        int b,n;
        read(b,n);
        fr(i,b) scanf("%lld", &M[i]);

        ll low=0,high=n+1;
        ll min_m=*min_element(M,M+b);

        while(high-low>1){
            ll m=(high+low)/2;

            ll tot=0;
            fr(i,b){
                tot += ceil(m*min_m, M[i]);
            }
            if(tot >= n) high=m;
            else low=m;
        }

        ll tm=low*min_m;

        fr(i,b){
            ll ppl=tm/M[i];
            M[i]*ppl;
        }

        ll tot=0;
        priority_queue<pll> events;
        fr(i,b){
            ll ppl=tm/M[i];
            tot+=ppl;
            events.push(pll(-M[i]*ppl,-i));
        }

        ++tot;
        int ans=0;
        while(1){
            auto cr=events.top();
            events.pop();
            if(tot==n){
                ans=-cr.second;
                break;
            }
            tot++;
            events.push(pll(cr.first-M[-cr.second],cr.second));
        }
        printf("Case #%d: %d\n",ii+1,ans+1);
    }
}
