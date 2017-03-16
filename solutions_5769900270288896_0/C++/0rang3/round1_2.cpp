#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<set>
#include<ctime>
#include<stack>
#include<list>
#include<cassert>  
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define sz(a) a.size()
#define ff first
#define ss second 
#define lli long long int

int main() {
		
	ios::sync_with_stdio(false);
	
	//clock_t start = std::clock();
	freopen ("inp.txt","r",stdin);
	freopen ("out.txt","w",stdout);
	//cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	
	
	int t,I,i,j,k;
	int n,r,c,gg,ans;
	int mat[18][18];
	cin>>t;
	rep(I,1,t+1){
		
		cin>>r>>c>>n;
		gg=r*c;
		ans = 1e9;
		for(i=0;i<(1<<gg);i++){
			if(__builtin_popcount(i) != n){
				continue;
			}
			memset(mat,-1,sizeof(mat));
			rep(j,0,r*c){
				if((1<<j)&i)
					mat[j/c][j-c*(j/c)] = 1;
			}
			int cur_ans = 0;
			rep(j,0,r)
			rep(k,0,c)
			if(mat[j][k] == 1){
				if(mat[j+1][k] == 1)
					cur_ans++;
				if(mat[j][k+1] == 1)
					cur_ans++;
			}
			ans = min(ans,cur_ans);
			
		}
		
		cout<<"Case #"<<I<<": "<<ans<<endl;
		
		
	}
	
	return 0;
}

