#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define CLR(a,b) memset(a,b,sizeof(a))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 1000+5;
int m[N];
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&m[i]);
    }
    int ans1 = 0, ans2 = 0;
    int rate = 0;
    for(int i = 0 ; i < n ; i ++){
        if(i > 0 && m[i] < m[i-1])ans1 += m[i-1] - m[i];
        if(i > 0 && m[i] <= m[i-1])rate = max(rate, m[i-1] - m[i]);
    }
    for(int i = 0 ; i < n-1 ; i ++){
        ans2 += min(m[i], rate);
    }
    printf("%d %d\n",ans1,ans2);
}
int main()
{
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/output.txt", "w", stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--){
        cas ++;
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}