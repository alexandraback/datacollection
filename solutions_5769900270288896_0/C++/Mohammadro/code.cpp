#include<iostream>
#include<cstdio>
#include<sstream>
#include<fstream>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<complex>
#include<bitset>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
#include<utility>

#define pb push_back
#define pp pop_back
#define xx first
#define yy second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;


const int maxn=20;
bool mark[maxn][maxn];
int n,m,ans=1e9,k;
void bt(int x,int y,int cnt){
	if(y==m){
		bt(x+1,0,cnt);
		return;
	}
	if(x==n){
		if(cnt!=0)return;
		int ret=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(mark[i][j] && mark[i+1][j])ret++;
				if(mark[i][j] && mark[i][j+1])ret++;
			}
		}
		ans=min(ans,ret);
		return;
	}
	if(cnt){
		mark[x][y]=true;
		bt(x,y+1,cnt-1);
		mark[x][y]=false;
	}
	bt(x,y+1,cnt);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){	
		cin>>n>>m>>k;
		ans=1e9;
		memset(mark,0,sizeof(mark));
		bt(0,0,k);
		cout<<"Case #"<<l<<": "<<ans<<endl;
	}
	return 0;
}
