#include <iostream>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>

#define mp make_pair
#define pb push_back
#define debug( x ) cout << #x << " = " << x << endl
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define f(i,a,b) for(int i = a ; i < b ; i++)
#define EPS 1E-9
#define INF 1000000000

using namespace std;

typedef pair<int,int> ii ;
typedef long long ll ;
typedef vector<int> vi;

int main(){

    int T; cin >> T;
    f(test,0,T){
        int n; cin >> n;
        vi plato;
        int maxdrop = 0;
        f(i,0,n){
            int m; cin >> m;
            plato.pb(m);
            if(i > 0){
                int dif = plato[i-1]-plato[i];
                maxdrop = max(maxdrop,dif);
            }
        }
        int val1 = 0;
        int val2 = 0;
        f(i,1,n){
            int ant = plato[i-1];
            int act = plato[i];
            if(act < ant){
                val1+=ant-act;
            }
        }
        f(i,0,n-1){
            int come = min(plato[i],maxdrop);
            val2+=come;
        }

        cout<<"Case #"<<test+1<<": "<<val1<<" "<<val2<<endl;
    }

    return 0;
}
