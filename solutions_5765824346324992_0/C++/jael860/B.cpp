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
vector<ll> tiempos;
ll B, N;

bool solve(int eleg){

    ll lo = 0;
    ll hi = N+2;
    while(lo <= hi){
        ll guess = lo + ( hi - lo)/2;

        ll tiempo = guess * tiempos[eleg];

        ll cuenta = 0;

        f(i,0,B){
            if(i == eleg) continue;

            ll t = tiempos[i];
            if(tiempo % t == 0 && i < eleg){
                cuenta+= tiempo/t + 1;
            }else if(tiempo%t == 0){
                cuenta += tiempo/t;
            }else{
                cuenta += tiempo/t + 1;
            }

        }

        ll totcortes = cuenta + guess + 1;

        if(totcortes == N){
            return true;
        }
        else if(totcortes < N){
            lo = guess + 1;
        }else{
            hi = guess - 1;
        }

    }
    return false;
}

int main(){

    int T; cin >> T;
    f(test,0,T){
        cin >> B >> N;

        f(i,0,B){
            ll a ; cin >> a;
            tiempos.pb(a);
        }

        int res = -1;
        f(i,0,B){
            bool es = solve(i);
            if(es){
                res = i+1;
                break;
            }
        }
        cout<<"Case #"<<test+1<<": "<<res<<endl;
        tiempos.clear();
    }


    return 0;
}
