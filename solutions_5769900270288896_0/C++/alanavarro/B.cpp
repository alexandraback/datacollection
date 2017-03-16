#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first

using namespace std;
typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
const int MAX = 1e6+6;

int ma[20][20];
int r,c,q;
bool ok(int x, int y ){
	return x >= 0 && y >= 0 && x < r && y < c;
}
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int rx, ry;
int get( int x, int y ){
	int w = 0;
	for( int i = 0 ; i < 4;i++ ){
		rx = x + dx[i];
		ry = y + dy[i];
		if( ok(rx,ry) && ma[rx][ry] ) w ++;
	}
	return w;
}

map < set < int > , int > dp;

int solve( set < int > cur ){
	if( dp.count(cur) ) return dp[cur];
	if( cur.size() == q ){
		set < int > :: iterator it;
		int aux;
		memset(ma,0,sizeof(ma));
		for( it = cur.begin(); it != cur.end(); it++ ){
			
			aux = (*it);
			//cout << aux << " ";
			ma[aux/c][aux%c] = 1;
		}
		//cout << endl;
		int ans = 0;
		for( int i = 0; i < r ;i++ ){
			for( int j = 0 ; j < c ; j++ ){
			//	cout << ma[i][j];
				if( ma[i][j] )
					ans += get(i,j);
				//cout << i << " " << j << " " << get(i,j) << endl;
			}
		//	cout << endl;
		}
	//	cout << endl;
		ans /= 2;
		return dp[cur] = ans;
	}
	int ret = 1e9+9;
	for( int i = 0 ; i < r*c; i++ ){
		if( cur.count(i) ) continue;
		cur.insert(i);
		ret = min( ret, solve(cur) );
		cur.erase(i);
	}
	return dp[cur] = ret;
}

int main(){
	
	freopen("a.in","r", stdin);
	freopen("a.out","w", stdout);
	
	int t;
	cin >> t;
	int ntc= 1, ans,s,w;
	int x,y;
	set < int > S;
	while( t-- ){
		cin >> r >> c >> q ;
		dp.clear();
		ans = solve(S);
		printf("Case #%d: %d\n", ntc, ans );
		ntc++;
	}

	return 0;
}
