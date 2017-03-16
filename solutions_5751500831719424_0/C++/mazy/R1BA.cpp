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
#define Uni(v) Sort(v),(v).erase(unique((v).begin(), (v).end()), (v).end())
#define cl(a,b) memset(a,b,sizeof(a))

const int oo=1000000;

#pragma warning(disable:4996)

#define QX "A"


int main()
{
//	freopen("" QX ".txt","r",stdin);
	freopen("" QX "-small-attempt0.in","r",stdin);freopen("" QX "-small-attempt0.out","w",stdout);
//	freopen("" QX "-small-attempt1.in","r",stdin);freopen("" QX "-small-attempt1.out","w",stdout);
//	freopen("" QX "-large.in","r",stdin);freopen("" QX "-large.out","w",stdout);
//	freopen("" QX "-large-practice.in","r",stdin);freopen("" QX "-large-practice.out","w",stdout);

    int T=0;
	scanf("%d",&T);
	for (int caseId=1;caseId<=T;caseId++)
	{
        // input
        int p[100];
        cl(p,0);
        int d[100];
        cl(d,0);
        int l[100];
		string s[100];
        int n;
        cin>>n;
        rep(i,n){
            cin>>s[i];
            l[i] = (int)s[i].length();
            //cout<<s[i]<<endl;
        }
        bool succ = true;
        int c = 0;
        while(true) {
            if (p[0]>=l[0]){
                // no target any more, check if it's true for all the strings
                rep(i,n){
                    if (p[i]<l[i]){
                        succ=false;
                        break;
                    }
                }
                break;
            }
            char t = s[0][p[0]];
            int tt = 0;
            rep(i,n) {
                int q = p[i];
                while(q<l[i] && s[i][q] == t) {
                    q++;
                }
                if (q==p[i]){
                    succ=false;
                    break;
                }
                d[i] = q-p[i];
                p[i]+=d[i];
                tt+=d[i];
            }
            if (!succ)
                break;
            int avg = (int)((double)tt/(double)n+0.5);
            rep(i,n){
                c+= abs(avg-d[i]);
            }
        }

        // output
        cout << "Case #"<<caseId<<": ";
        if (!succ) {
            cout<<"Fegla Won"<<endl;
        } else {
            cout<<c<<endl;
        }

	}
    return 0;
}