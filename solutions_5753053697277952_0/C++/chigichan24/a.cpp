#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
const long long LINF = 1e18;
const double EPS = 1e-8;
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); ++i)
#define rep(i,j) reps(i,0,j)
#define repsr(i,j,k) for(int i = (j); i >= (k); --i)
#define repr(i,j) repsr(i,j,0)
#define all(a) a.begin(),a.end()
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef pair<int, ll> Pil;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector <string> solve(int len,vi res){
	vector<string> ans;
	int sum = 0;

	priority_queue <Pii> Q;
	int mx = -INF;
	int idx = 0;
	rep(i,len){
		sum += res[i];
		if(mx < res[i]){
			mx = res[i];
			idx = i;
		}
	}

	if(sum % 2 == 1){
		string tmp = "";
		tmp += 'A'+idx;
		ans.pb(tmp);
		res[idx]--;
	}

	rep(i,len){
		if(res[i] == 0)continue;
		Q.push(Pii(res[i],i));
	}

	while(!Q.empty()){
		Pii p1 = Q.top();Q.pop();
		if(Q.size()>0){
			Pii p2 = Q.top();Q.pop();
			p1.fr--;
			p2.fr--;
			string tmp="";
			tmp += p1.sc+'A';
			tmp += p2.sc+'A';
			ans.pb(tmp);
			if(p1.fr > 0)Q.push(p1);
			if(p2.fr > 0)Q.push(p2);
		}
	}



	return ans;
}
int main(){
	int Q;
	scanf("%d",&Q);
	rep(q,Q){
		//input
		int N;
		scanf("%d",&N);
		vi res;
		rep(i,N){
			int s;
			scanf("%d",&s);
			res.pb(s);
		}
		vector < string > ans = solve(N,res);
		//output
		printf("Case #%d: ",q+1);
		rep(i,ans.size()){
			printf("%s%c",ans[i].c_str(),i==ans.size()-1?'\n':' ');
		}
	}
	return 0;
}
