#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

#define fi          first
#define se          second
#define mp 			make_pair
#define pb          push_back
#define forall(i,a,b)               for(int i=a;i<b;++i)
#define max(a,b)                    ( (a) > (b) ? (a) : (b))
#define min(a,b)                    ( (a) < (b) ? (a) : (b))
#define mes(a,b)					memset(a,b,sizeof a)
#define endl			    		"\n"
#define ll 							long long
const int oo = 1000000009;
const double eps = 1e-9;
const int mod = 1000000007;

pi nos[30];

bool comp(pi a,pi b) {return a.fi>b.fi;}

char k(int p){
	return (char)(((int)'A')+p);
}

int main(){
	int t;cin >> t;
	forall(test,0,t){
		int n,tot=0,su=0;cin >> n;
		memset(nos,0,sizeof nos);
		cout << "Case #" << test+1 << ": "; 
		forall(i,0,n) {
			cin >> nos[i].fi;
			nos[i].se=i;
			su+=nos[i].fi;
		}
		sort(nos,nos+n,comp);
		if(su%2==1) {
			cout << k(nos[0].se) << ' ';
			++tot;
			nos[0].fi-=1;
		}
		while(tot!=su){
			sort(nos,nos+n,comp);
			cout << k(nos[0].se) << k(nos[1].se) << ' ';
			tot+=2;
			nos[0].fi-=1;
			nos[1].fi-=1;	
		}
		cout << endl;
	}
}