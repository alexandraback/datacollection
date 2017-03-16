#include <bits/stdc++.h>
using namespace std;
#define msg(x) cout<<#x<<" = "<<x<<endl;
#define N 110
char mapa[N][N];
int sum[N];
vector<int> matrix[N];
int main() {
    ios_base::sync_with_stdio(0);
	int T, n, pos, len, cnt, m;
	char c;
	cin>>T;
	for(int caso=1 ; caso<=T ; caso++) {
		for(int i=0 ; i<N ; i++) matrix[i].clear();
		cin>>n;
		for(int i=0 ; i<n ; i++) cin>>mapa[i];
		vector<char> v;
		pos = 0;
		len = strlen(mapa[0]);
		while( pos < len ) {
			c = mapa[0][pos];
			while( pos < len && c == mapa[0][pos] ) {
				pos++;
			}
			v.push_back(c);
		}
		m = v.size();
		bool flag = true;
		for(int i=0 ; flag && i<n ; i++) {
			pos = 0;
			len = strlen(mapa[i]);
			vector<char> tmp;
			while( pos < len ) {
				c = mapa[i][pos];
				cnt = 0;
				while( pos < len && c == mapa[i][pos] ) {
					cnt++;
					pos++;
				}
				tmp.push_back(c);
				matrix[i].push_back(cnt);
			}	
			if( (int)tmp.size() != m ) {
				flag = false;
				break;
			}
			for(int k=0 ; k<m ; k++) {
				if( tmp[k] != v[k] ) {
					flag = false;
					break;
				}
			}
		}
		if( flag == false ) {
			cout<<"Case #"<<caso<<": Fegla Won"<<endl;
			continue;
		} 
		int ans = 0;
		for(int i=0 ; i<m ; i++) {
			vector<int> tmp;
			for(int k=0 ; k<n ; k++) {
				tmp.push_back(matrix[k][i]);
			}
			sort(tmp.begin(), tmp.end());
			sum[0] = 0;
			for(int k=1 ; k<=n ; k++) sum[k] = sum[k - 1] + tmp[k - 1];
			int minimo = (1<<30);
			for(int k=1 ; k<=n ; k++) {
				minimo = min(minimo, ((k-1) * tmp[k-1] - sum[k-1]) +  ((sum[n] - sum[k]) - (n - k) * tmp[k-1]) );
			}
			ans += minimo;
		}
		cout<<"Case #"<<caso<<": "<<ans<<endl;
	}    
    return 0;
}