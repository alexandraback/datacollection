#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<sstream>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second


#ifdef __BORLANDC__
	typedef __int64 ll;
#else
	typedef long long ll;
#endif

const int INF = 1000000000;
const int T = 16;

int r,c,n;
void input(){
	cin>>r>>c>>n;
}


int cntstate(int state){
	
	int room[T][T]={0};
	
	rep(i,r){
		rep(j,c){
			int k = i*c+j;
			if((state&(1<<k))>0){
				room[i][j]=1;
			}
		}
	}
	
	int ret = 0;
	rep(i,T-1){
		rep(j,T-1){
			if(room[i][j]!=1)continue;
			if(room[i+1][j]==1)ret++;
			if(room[i][j+1]==1)ret++;
		}
	}
	return ret;
}
int bitcnt(int state){
	int ret = 0;
	while(state!=0){
		ret+=state%2;
		state/=2;
	}
	return ret;
}
int solve(){
	
	int t = r*c;
	int ret = INF;
	
	for(int i=0;i<(1<<t);i++){
		if(bitcnt(i)==n)ret = min(ret, cntstate(i));
	}
	return ret;
}

int main(){
	int ttt;
	cin>>ttt;
	
	rep(i,ttt){
		input();
		cout<<"Case #"<<(i+1)<<": "<<solve()<<endl;
	}
}