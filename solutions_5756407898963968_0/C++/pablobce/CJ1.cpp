#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

#define forsn(i,s, n) for(int i=(int)s; i<(int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define fore(i,n) forn(i,n.size())
#define fori(i, n) for(typeof n.begin() i=n.begin(); i!=n.end();i++)
#define RAYA cout<<"-----------------"<<endl;
#define dbg(x) cout<<#x<<":"<<(x)<<endl;

typedef long long int tint;
typedef long double ldouble;
#define pii pair <int,int>

#define pb push_back
#define mp make_pair
#define f first
#define s second

const tint INF=2000000000;



int main(){
	freopen("CJ1.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		int n;
		int tab[4][4];
		map <int,int> cont;
		forn(k,2){
			cin>>n; n--;
			forn(i,4)forn(j,4)cin>>tab[i][j];
			forn(j,4)cont[tab[n][j]]++;
		}
		int res;
		int cant=0;
		fori(i,cont) if(i->s==2){			
			cant++;
			res=i->f;
		}
		if(cant==0) cout<<"Case #"<<1+caso<<": Volunteer cheated!"<<endl;
		else if(cant==1) cout<<"Case #"<<1+caso<<": "<<res<<endl; 	
		else cout<<"Case #"<<1+caso<<": Bad magician!"<<endl;
	}	
    return 0;
}
