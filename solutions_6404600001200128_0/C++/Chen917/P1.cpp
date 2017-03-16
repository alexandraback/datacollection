
#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vI;
typedef vector<string> vS;
typedef pair<int, int> pI;
typedef map<int, int> mI;
typedef map<string, int> mSI;
typedef set<int> sI;
typedef set<pI> spI;
typedef priority_queue<int> qmax;
typedef priority_queue<int, vector<int>, greater<int> >qmin;
typedef map<int, int>::iterator mI_it;
typedef set<int>::iterator sI_it;

#define TWO(k)  (1<<(k))
#define LTWO(k) (((LL)(1)<<(k)))
#define MIN(a,b) ( (a)<(b)?(a):(b) )
#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define LS(x) 	 ((x)<<1)
#define RS(x) 	 (((x)<<1)+1)
#define MP make_pair
#define PB push_back
#define F0(i, n) for( int (i) = 0; (i) < (n); (i)++)
#define F1(i, n) for( int (i) = 1; (i) <= (n); (i)++)
#define zero(i) memset((i),0,sizeof((i)))


int main()
{
    freopen("out.txt","w",stdout);
    freopen("A-small-attempt0 (1).in","r",stdin);
    int t, n;
    int a[1009];
    scanf("%d", &t);
    for(int p = 1; p <= t; p++){
        int ans1 = 0, ans2 = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        int gap = 0;
        for(int i = 0; i < n-1; i++){
            int tmp = a[i] - a[i+1];
            if(tmp > 0){
                ans1 += tmp;
                if(gap < tmp) gap = tmp;
            }
        }
        for(int i = 0; i < n-1; i++){
            if(a[i] < gap) ans2 += a[i];
            else ans2 += gap;
        }
        cout<<"Case #"<<p<<": ";
        cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}
