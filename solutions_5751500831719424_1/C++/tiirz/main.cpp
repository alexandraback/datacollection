#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <bitset>
#define  pb push_back
#define mp make_pair
#define pii pair< pair<int,int> , pair<int,int> >
#define rep(i,s,n) for(int i=s;i<n;++i)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int buf_i;
int in(){
    scanf("%d", &buf_i);
    return buf_i;
}
const int INF=~(1<<31);
const ll LINF=~(1LL<<63);

const double eps=1e-6;
ll gcd(ll a, ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}



int main(){
#ifdef SSU
    freopen("in2.txt","r", stdin);
    freopen("outcj2.txt", "w", stdout);
#else
    //  freopen("g.in","r", stdin);
    // freopen("g.out", "w", stdout);
#endif

    int T=in();
    for(int t=0;t<T;++t){
        printf("Case #%d: ",t+1);
        int n=in();
        vector<string> v;
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            v.pb(s);
        }
        set<string> m;
        for(int i=0;i<n;++i){
            string cur="";
            string c=v[i];
            for(int j=0;j<c.size();++j){
                if(cur.size()==0 || cur[cur.size()-1]!=c[j]){
                    cur.pb(c[j]);
                }
            }
            m.insert(cur);
        }
        if(m.size()>1){
            printf("Fegla Won\n");
        }else{
            string mask=*m.begin();
            ll res=0;
            vector<int> g((int)mask.size(),0);
            for(int i=0;i<n;++i){
                string cur=v[i];
                for(int j=0,k=0;k<mask.size();++k){
                    char cc=mask[k];
                    int count=0;
                    while(cur[j]==cc){
                        count++;
                        ++j;
                    }
                    g[k]+=(count);
                }
            }
            vector<int> add(g.size(),0);
            for(int i=0;i<g.size();++i){
                int cur=g[i];
                int curres=INF;
                int r=0;
                for(int j=1;j<=100;++j){
                    int ccc=std::abs(j*n-cur);
                    if(ccc<curres){
                        curres=ccc;
                        r=j;
                    }
                }
                add[i]=r;
            }
            for(int i=0;i<n;++i){
                string cur=v[i];
                for(int j=0,k=0;k<mask.size();++k){
                    char cc=mask[k];
                    int count=0;
                    while(cur[j]==cc){
                        count++;
                        ++j;
                    }
                    res+=std::abs(count-add[k]);
                }
            }
            printf("%lld\n",res);

        }

    }











    return 0;
}
