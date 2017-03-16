
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
int n, b;
int bar[1009];
vector<int> arr;

int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
}

int lcm(int x, int y){
    return x * y / gcd(x,y);
}

int solve(){
    if(n <= b) return n;
    else{
        
        int loop = 1;
        for(int i = 1; i <= b; i++){
            loop = lcm(loop, bar[i]);
            arr.push_back(i);
        }
        for(int i = 1; i < loop; i++){
            for(int j = 1; j <= b; j++){
                if(i % bar[j] == 0) arr.push_back(j);
            }
        }
        int l = arr.size();
//        cout<<"l="<<l<<endl;
        if(n % l == 0) return arr[l-1];
        else return arr[n%l-1];
    }
}

int main()
{
    freopen("out.txt","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    int t;
    scanf("%d", &t);
    for(int p = 1; p <= t; p++){//testcase #p
        arr.clear();
        scanf("%d%d", &b, &n);
        for(int i = 1; i <= b; i++) scanf("%d", &bar[i]);
        int ans = solve();
        cout<<"Case #"<<p<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
