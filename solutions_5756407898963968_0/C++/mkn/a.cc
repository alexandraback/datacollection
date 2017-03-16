#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>


using namespace std;

#define repp(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define rep(i,n) repp(i,0,(n)-1)

#define mp make_pair
#define pb push_back

void solve(){
	int ans1;
	cin >> ans1; --ans1;
	int a[4][4];
	rep(i,4)rep(j,4) cin >> a[i][j];
	int ans2;
	cin >> ans2; --ans2;
	int b[4][4];
	rep(i,4)rep(j,4) cin >> b[i][j];

	int cnt=0;
	int ans;
	rep(i,4)rep(j,4) if(a[ans1][i] == b[ans2][j]) {++cnt; ans = i;}

	if(cnt == 0){
		cout << "Volunteer cheated!";
	}else if(cnt == 1){
		cout << a[ans1][ans];
	}else{
		cout << "Bad magician!";
	}
	
}


int main(){
	int T;
	cin >> T;
	rep(i,T){
		cout << "Case #" << i+1 << ": ";
		solve();
		cout << endl;
	}
	return 0;
}


