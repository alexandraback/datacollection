#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

typedef long long ll;
const double pi=acos(-1.0);
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
typedef map<string, int> simp;
#define sz(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define rep(i,b) for(int i=0;i<b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
template<class T> inline void Swap(T &a,T &b){T c=a;a=b;b=c;}
#define Sort(v) sort((v).begin(), (v).end())
#define RSort(v) sort((v).rbegin(), (v).rend())
#define Uni(v) Sort(v),(v).erase(unique((v).begin(), (v).end()), (v).end())
#define cl(a,b) memset(a,b,sizeof(a))
#define LOG if (log) cout
const int oo=1000000;

#pragma warning(disable:4996)

#define QX "C"

int N;
ll X[3001];
ll Y[3001];

int side(int i, int j, int k){
    if (X[i]==X[j]){
        if (X[k]>X[i]){
            return 1;
        }else if (X[k]==X[i]){
            return 0;
        }else{
            return -1;
        }
    }
    else if (Y[i]==Y[j]){
        if (Y[k]>Y[i]){
            return 1;
        }else if (Y[k]==Y[i]){
            return 0;
        }else{
            return -1;
        }
    }
    ll x2_x1_y=(Y[j]-Y[i])*X[k]+(Y[i]*X[j]-X[i]*Y[j]);
    ll x2_x1_yk=Y[k]*(X[j]-X[i]);
    if (x2_x1_yk>x2_x1_y)
        return 1;
    else if (x2_x1_yk==x2_x1_y)
        return 0;
    else
        return -1;
}

int main()
{
//	freopen("" QX ".txt","r",stdin);
//	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
    for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        cin>>N;
        rep(i,N){
            cin>>X[i]>>Y[i];
        }
        int ans[3001];
        bool log=false;
        rep(i,N){
            int mn=N;
            //log= (i==4);
            LOG<<"i="<<i<<endl;
            rep(j,N){
                if (j==i) continue;
                int a=0,b=0;
                LOG<<"j="<<j<<endl;
                rep(k,N){
                    if (k==i||k==j) continue;
                    int flg= side(i,j,k);
                    if (flg>0){
                        a++;
                    }else if (flg<0){
                        b++;
                    }
                    LOG<<"k="<<k<<" side="<<flg<<endl;
                }
                if (mn>a) mn=a;
                if (mn>b) mn=b;
                if (mn==0) break;
            }
            ans[i]=mn;
        }
        // output:
        cout << "Case #"<<caseId<<":"<<endl;
        rep(i,N){
            cout<<ans[i]<<endl;
        }
	}
    return 0;
}