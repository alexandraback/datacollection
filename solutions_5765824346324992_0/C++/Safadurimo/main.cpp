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



int ggT(int u, int v) {
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

 int kgV( int a,  int b){
    return (a * b) / ggT(a, b);
}

 int kgV(vi v){
    int r=1;
    REP(i,0,sz(v)){
        r=kgV(r,v[i]);
    }
    return r;
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
        int b,n;
        cin >> b >> n;
        vi m(b,0);
        REP(i,0,b) cin >> m[i];
        int k=kgV(m);
        vi q;
        REP(i,0,b) q.push_back(i);
        vi w=m;
        while(k>0){
            int x =*min_element(all(w));
            k-=x;
            if(k!=0){
            REP(i,0,b){
                w[i]-=x;
                if(w[i]==0){
                    q.push_back(i);
                    w[i]=m[i];
                }
            }
            }
            
        }
        
        
        cout << "Case #" << (t+1) << ": " << q[(n-1) % sz(q)]+1 << endl;
    }
    
    return 0;
    
}
