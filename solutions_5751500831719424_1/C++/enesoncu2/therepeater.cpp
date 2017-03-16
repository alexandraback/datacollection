#include<bits/stdc++.h>

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define all(gg)	gg.begin(),gg.end()
#define foreach( gg,it )	for( typeof(gg.begin())	it=gg.begin();it!=gg.end();it++ )
#define FP( ii,aa,bb )	for( int ii=aa;ii<=bb;ii++ )
#define FM( ii,aa,bb )	for( int ii=aa;ii>=bb;ii-- )

using namespace std;

vector<int>	v[200],p;
int n;
string arr[200],s;

int findresult(){
	sort( all(p) );
	int n = p.size();
	int median = p[n/2];
	int res=0;
	foreach( p,it )	res += abs( (*it)-median );
	return res;
}

int main(){
	int t;
	cin >> t;
	FP( CASE,1,t ){
		cin >> n;
		FP( i,1,n ){
			v[i].clear();
			arr[i].clear();
			cin >> s;
			foreach( s,it ){
				if( it==s.begin() or *it!=*(it-1) ){
					arr[i] += *it;
					v[i].pb(1);
				}
				else{
					v[i].back()++;
				}
			}
		}
		cout << "Case #" << CASE << ": ";
		int sol=1;
		FP( i,1,n-1 )
			if( arr[i]!=arr[i+1] ){
				sol = 0;
				break;
			}
		if( !sol ){
			cout << "Fegla Won" << endl;
			continue;
		}
		int res=0;
		FP( i,0,arr[1].size()-1 ){
			p.clear();
			FP( j,1,n )
				p.pb( v[j][i] );
			res += findresult();
		}
		cout << res << endl;
	}
}
