#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <limits>
#include <string>
#include <cstring> // memset
#include <iostream> // cin, cout
#include <fstream> // io redirection
#include <sstream> // topcoder testcase

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
#define OUTBOOL(boolean,true_string,false_string) cout << ((boolean) ? true_string : false_string)<< endl

#define MOD 1000000007

int main(){
    
    
#ifndef ONLINE_JUDGE
    ifstream arq(getenv("INPUT"));
    cin.rdbuf(arq.rdbuf());
    
    ofstream brq(getenv("OUTPUT"));
    cout.rdbuf(brq.rdbuf());
#endif
    // Number of Testcases
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int n; cin>> n;
        vi m(n,0);
        REP(i,0,n) cin>> m[i];
        
        ll y,z;
        y=0;
        REP(i,1,n){
            y+=max(m[i-1]-m[i],0);
        }
        
        z=0;
        int r=0;
        REP(i,1,n){
            r=max(m[i-1]-m[i],r);
        }
        REP(i,0,n-1){
            z+=min(m[i],r);
        }
        
        
        cout << "Case #" << (t+1) << ": " << y << " " << z << endl;
    }
    
    return 0;
    
}
