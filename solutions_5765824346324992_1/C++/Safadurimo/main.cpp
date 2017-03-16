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

vector<ll> m;
int b,n;


ll kundeN(ll mi){
    ll res=0;
    REP(i,0,b){
        res+=mi/m[i]+1;
    }
    return res;
}



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
        
        cin >> b >> n;
        m.resize(b);
        REP(i,0,b) cin >> m[i];
        ll res=0;
        if(n<=b){
            res=n;
        }
        else {
        
        ll lo,hi;
        lo=0;
        hi=2;
        
        ll mid;
        // find the high
        while(kundeN(hi)<n) hi*=2;
        
        
        
        
        
        while(lo<hi){
            mid=lo + (hi-lo)/2;
            if(kundeN(mid)>=n)
                hi=mid;
            else
                lo=mid+1;
        }
        
        n-=kundeN(lo-1);
        
        res=-1;
        REP(i,0,b){
            if(lo%m[i]==0) n--;
            
            if(n==0) res=i+1;
        }
        
        }
        
        
        cout << "Case #" << (t+1) << ": " << res << endl;
    }
    
    return 0;
    
}
