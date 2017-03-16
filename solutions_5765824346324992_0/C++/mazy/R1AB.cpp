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
typedef unsigned long long ull;
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
#define Uni(v) Sort(v),(v).erase(unique((v).begin(), (v).end()), (v).end())
#define cl(a,b) memset(a,b,sizeof(a))

const int oo=1000000;

#pragma warning(disable:4996)

#define QX "B"

ull B,N;

ull M[1001];

ull find(ull tm) {
    ull ans=B;
    rep(i,B){
        ans += tm/M[i];
    }
    return ans;
}

int main()
{
//	freopen("" QX ".txt","r",stdin);
//	freopen("" QX "-small-attempt0.in","r",stdin);//freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
	freopen("" QX "-small-attempt2.in","r",stdin);freopen("" QX "-small-attempt2.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);

    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        cin>>B>>N;
        cl(M,0);
        rep(i,B){
            cin>>M[i];
		}
        int ans=1;
        if (B==1){
            cout << "Case #"<<caseId<<": "<<ans<<"\n";
            continue;
        }
        if (N<=B){
            cout << "Case #"<<caseId<<": "<<N<<"\n";
            continue;
        }

        ull total=1;
        rep(i,B){
            total*=M[i];
        }
        ull ct=0;
        ull t[1001];
        cl(t,0);
        while(true){
            int in=0;
            ull mtm=t[0];
            rep(i,B){
                if (mtm>t[i]){
                    mtm=t[i];
                    in=i;
                }
            }
            if (mtm>total)
                break;
            t[in]+=M[in];
            ct++;
        }
        assert(ct>B);
        ct-=B;
        ull lft=(N-B)%ct;
        if (lft==0){
            ans=B;
        }else{
            lft+=B;
            cl(t,0);
            ct=0;
            while(true){
                int in=0;
                ull mtm=t[0];
                rep(i,B){
                    if (mtm>t[i]){
                        mtm=t[i];
                        in=i;
                    }
                }
                t[in]+=M[in];
                ct++;
            if (ct==lft){
                ans=in+1;
                break;
            }

            }
        }
        /*ull a=0;
        ull b = 1ULL<<48;
        while(a+1<b) {
            //cout<<a<<" "<<b<<endl;
            ull tm=(a+b)/2;
            ull f=find(tm);
            if (f>=N){
                b=tm-1;
            } else if (f<N) {
                a=tm;
            }
        }
        ll ct = find(a);
        if (a>0){
            if (!(ct<N && ct+B+B>=N)){
                cout<<ct<<" "<<B<<" "<<N<<endl;
            }
            assert(ct<N && ct+B+B>=N);
        }else{
            ct=0;
        }
        ull t[1001];
        rep(i,B){
            t[i]=a/M[i]*M[i];
        }
        while(true){
            int in=0;
            ull mtm=t[0];
            rep(i,B){
                if (mtm>t[i]){
                    mtm=t[i];
                    in=i;
                }
            }
            t[in]+=M[in];
            ct++;
            if (ct==N){
                ans=in+1;
                break;
            }
        }*/

        // output
        cout << "Case #"<<caseId<<": "<<ans<<"\n";
	}
    return 0;
}
