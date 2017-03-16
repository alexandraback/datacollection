#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ostream>
#include <queue>
#include <cmath>
#include <climits>
#include <utility>
#include <fstream>
#include <memory>
#include <sstream>
#include <set>
#include <iterator>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
#define FOR(a, b, n) for(int (a) = (b); (a) < (n); ++(a))
#define FORE(a, b, n) for(int (a) = (b); (a) <= (n); ++(a))
#define ITE(a, v) for(auto (a) = v.begin(); (a) != v.end(); ++(a))
#define LL long long
#define ALL(v) v.begin(),v.end()
#define ZERO(v) memset(v, 0, sizeof v)
#define NEG(v)  memset(v, -1, sizeof v)
#define F first
#define S second
#define LD double
#define pw(x) (1LL << (x))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define PI 3.141592653589793
#define PII pair<LL, LL>
#define INF 0x3f3f3f3f
#define FUL(x) memset(x, 0x3f, sizeof(x));
#define debug(args...) {cerr << #args << " = "; errDebug(args); cerr << endl;}
void errDebug() {}
template<typename T, typename... Args>
void errDebug(T a, Args... args) {
    cerr << a << ' ';
    errDebug(args...);
}

int n;
struct node
{
    char c;
    int cnt;
} a[30];
bool cmp(node aa, node bb)
{
    return aa.cnt > bb.cnt;
}
void solve()
{
    int tot = 0;
    FOR(i,0,n)
        tot  += a[i].cnt;
    vector<char> output;
    while(tot)
    {
        sort(a, a + n, cmp);
        output.clear();
        output.PB(a[0].c);
        a[0].cnt--;
        tot--;
        sort(a, a + n, cmp);
        if(tot != 0 && a[0].cnt * 2 > tot)
        {
            output.PB(a[0].c);
            a[0].cnt--;
            tot--;
        }
        FOR(i,0,output.size())
        cout << output[i];
        cout << " ";

    }
    cout << endl;
}
int main(){
    int T;
    cin >> T;
    FOR(z,0,T)
    {
        cin >> n;
        FOR(i,0,n)
        {
            a[i].c = 'A' + i;
            cin >> a[i].cnt;
        }
        cout << "Case #" << z + 1 << ": ";
        solve();
    }
    return 0;
}