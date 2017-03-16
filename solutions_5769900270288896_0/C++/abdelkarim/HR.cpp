#include <bits/stdc++.h>

using namespace std;



int calc_mask(int msk ,int r,int c,int n){
	vector<vector<bool> > vec (r , vector<bool>(c,0) );
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			int bit = j + c*i;
			if(msk & (1<<bit)){
				vec[i][j] = 1;
				n--;
			}
		}
	}
	if(n!=0)return (1<<30);
	int cnt = 0;
	for(int i=0;i<r;i++){
		for(int j=1;j<c;j++){
			cnt += vec[i][j] & vec[i][j-1];
		}
	}

	for(int i=1;i<r;i++)
		for(int j=0;j<c;j++)
			cnt += vec[i-1][j] & vec[i][j];
	return cnt;
}


int main(){
	freopen("in.in","rt",stdin);
	freopen("out.out","wt",stdout);
	int ans;
	int t,r,c,n,cs=0;
	cin>>t;
	while(t--){
		cs++;
		cin>>r>>c>>n;
		ans = 1<<30;
		for(int msk=0;msk<(1<<(r*c));msk++){
			ans = min(ans ,calc_mask(msk,r,c,n));
		}
		printf("Case #%d: %d\n",cs,ans);
	}

}




/*
int Reverse(int n){
	int ans = 0;
	while(n){
		ans *=10;
		ans += n%10;
		n/=10;
	}
	return ans;
}

vector<bool> vis;
int bfs(int n){
	queue<int> q;
	vis.clear();
	vis.resize(6654321,0);
	vis[1] = 1;
	q.push(1);
	int lvl = 0;
	while(q.size()){
		int sz = q.size();
		lvl++;
		while(sz--){
			int cur = q.front();
			q.pop();
			if(cur == n)return lvl;

			int r = Reverse(cur);
			if(!vis[r]){
				vis[r]=1;
				q.push(r);
			}
			int nxt = cur+1;
			if(!vis[nxt]){
				vis[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	return n;
}

int main(){
	freopen("in.in","rt",stdin);
	//freopen("out.out","wt",stdout);
	int t;
	cin>>t;
	int cs = 0;
	for(int i=1;i<20000;i++){
		int n = i;
		//cin>>n;
		cout<<"Case #"<<i<<": ";
		cout<<bfs(n)<<endl;
	}

}
*/
