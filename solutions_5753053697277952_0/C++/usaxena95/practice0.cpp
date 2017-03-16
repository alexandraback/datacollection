/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin);freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define LL signed long long int
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define rep(i,from,to) for(int i=(from);i <= (to); ++i)
#define pii pair<int,int>

vector<int> G[2*100000+5];
int N, F[266];
bool valid(){
	int S = 0;
	rep(i,1,N)S += F[i];
	rep(i,1,N){
		if(2*F[i] > S){
			return 0;
		}
	}
	return 1;
}
string give(){
	int S = 0;
	string x="";
	for(int i=1;i<=N;++i){
		if(F[i]==0)continue;
		F[i]--;
		if(valid()){
			x += char('A'+i-1);
			return x;
		}
		else{
			F[i]++;
		}
	}
	for(int i=1;i<=N;++i){
		if(F[i]==0)continue;
		for(int j=1;j<=N;++j){
			if(F[j]==0)
				continue;
			F[i]--;
			F[j]--;
			if(valid()){
				x += char('A'+i-1);
				x += char('A'+j-1);
				return x;
			}
			else{
				F[i]++;
				F[j]++;
			}
		}
	}
	assert(0);
}
int main(){
	fre;
	int T;
	cin>>T;
	for(int t=1;t<=T;++t){
		printf("Case #%d:",t);
		cin>>N;
		int S = 0;
		rep(i,1,N)scan(F[i]),S+=F[i];
		while(S>0){
			string x = give();
			S -= x.size();
			cout<<' '<<x;
		}
		cout<<endl;
	}
}
