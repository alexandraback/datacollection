#include<iostream>
#include<cmath>
#include<iomanip> //Per quan vulguis fer 'cout' currats (p.e. amb 4 decimals)
#include<vector>
#include<map>
#include<queue>
#include<fstream> //Per a fer que l'entrada i/o la sortida siguin fitxers
#include<algorithm>
#include<string>
#include<stack> //Poc útil
#include<numeric> //Poc útil
#include<set>
#include<sstream> //Per entrades complicades on no+ amb el cin no es pot
#include<list> //Poc útil

//cout.setf(ios::fixed);
//cout.precision(11);
// for(iMII it=M.begin();it!=M.end();++it) , per recorre map
//sort(V.begin(), V.end(), greater<int>());  // o reverse(V.begin, V.end)

#define INF 1000000000
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl //Si vols saber el valor d'una variable fas debug(a);
#define FOR(x,y) for(int x=0;x<y;x++)             //En general el 'cerr' va bé per debuguejar (p.e. cerr<<"Hey!"<<endl;
#define FORU(x,y) for(int x=1;x<=y;x++)           //Pq així saps el que has de borrar abans d'enviar i si te l'oblides a vegades no passa res
using namespace std;


typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VP;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII; //L'iterador més utiltizat
//Personalitza'l al teu gust! ^^ espero que t'agradi
ll R, C;ll n; 
VVI V;
ll resultat;

void funcio(int r, int f, ll res, ll posats) {
    ++f; 
    if ( f >= C) { ++r; f = 0;}
    if ( r == R or posats > n){
        if(posats ==n) resultat = min(res, resultat);
        return;
    }

    funcio(r, f, res, posats); //no fer res;
    if (f > 0) res +=V[r][f-1];
    if (r > 0) res += V[r-1][f];
    V[r][f] = 1;
    funcio(r, f, res, posats+1);
    if (f > 0) res -=V[r][f-1];
    if (r > 0) res -= V[r-1][f];
    V[r][f] = 0;
}



int main(){
    ios_base::sync_with_stdio(false);
    freopen("inputB.txt","r",stdin);
    freopen("output.out","w",stdout);
    ll N; cin >> N;
    FOR(t, N) {
    cin >> R >> C;
    cin >> n;
    V = VVI(R, VI(C));
    resultat = INF;
    funcio(0,0, 0, 0);
    V[0][0] = 1;
    funcio(0,0, 0, 1);
    
    cout << "Case #" << t+1 << ": " << resultat << endl;
     
    }
    
}
