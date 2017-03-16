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
int b,n;

LL getSum(LL time){
    LL sum = 0;
    for(int i = 0 ; i < b ; i ++){
        sum += time / m[i] + 1;
    }
    return sum;
}
bool le(LL time){
    LL sum = getSum(time);
    return sum < n ? true : false;
}
void solve()
{
    scanf("%d%d",&b,&n);
    for(int i = 0 ; i < b ; i ++){
        scanf("%d",&m[i]);
    }
    LL lb = 0, rb = 100000LL * INT_MAX;
    while(lb + 1 < rb){
        LL mid = (lb + rb) >> 1;
        if(le(mid)) lb = mid;
        else rb = mid;
    }
    LL t = lb;
    LL cnt = getSum(t);
    LL left = n - cnt;
    t ++;
    if(left == 0){
        printf("%d\n",n);
        return;
    }
    for(int i = 0 ; i < b ; i ++){
        if(t % m[i] == 0){
            left --;
            if(left == 0){
                printf("%d\n",i + 1);
                return;
            }
        }
    }
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