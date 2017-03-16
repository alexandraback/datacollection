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


typedef long long ll ;
typedef vector<ll> vi;
typedef pair<ll,ll> ii ;
typedef vector<ii> vii;

ll calc(ii p1, ii p2, ii p3){

    ll x1 = p1.first;
    ll y1 =p1.second;
    ll x2 = p2.first;
    ll y2 = p2.second;

    ll x3 = p3.first;
    ll y3 = p3.second;

    ll val = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    return val;
}

int main(){

    int T; cin >> T;
    f(test,0,T){
        int n; cin >> n;
        vii puntos;

        f(i,0,n){
            ll x, y;
            cin >> x >> y;
            puntos.pb(mp(x,y));
        }
        vector<vi> lista(n);

        f(i,0,n){
            f(j,i+1,n){
                int cnt1 = 0;
                int cnt2 = 0;


                f(k,0,n){
                    if(k == j || k == i) continue;
                    ll val = calc(puntos[i],puntos[j],puntos[k]);
                    if(val > 0){
                        cnt1++;
                    }
                    else if(val < 0){
                        cnt2++;
                    }
                }

                int v = min(cnt1,cnt2);
                lista[i].pb(v);
                lista[j].pb(v);
            }
        }
        cout<<"Case #"<<test+1<<": "<<endl;
        if(n  > 1)
            f(i,0,n){
                vi vec = lista[i];
                sort(all(vec));
                cout<<vec[0]<<endl;
            }
        else{
            cout<<0<<endl;
        }

    }
    return 0;
}
