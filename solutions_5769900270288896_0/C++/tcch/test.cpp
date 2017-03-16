#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void solve(){
	int R,C,N,r,c,n,A;
	cin>>R>>C>>N;
	if(min(R,C)==1){
		int L = max(R,C);
		if(L%2==0){
			L = L/2;
			if(N<=L) cout<<0<<endl;
			else cout<<1+(N-L-1)*2<<endl;
		}
		else{
			L = L/2+1;
			if(N<=L) cout<<0<<endl;
			else cout<<2*(N-L)<<endl;
		}
		return;
	}

	A = R*C;
	if(A%2==0 && N<=A/2){
		cout<<0<<endl;
		return;
	}
	if(A%2==1 && N<=A/2+1){
		cout<<0<<endl;
		return;
	}
	if(A%2==0){
		if(N<=A/2+2){
			cout<<(N-A/2)*2<<endl;
		}
		else if(N<=A/2-2+R+C){
			cout<<4+(N-A/2-2)*3<<endl;
		}
		else cout<<4+(R+C-4)*3+4*(N-A/2-R-C+2)<<endl;
		return;
	}
	if(A%2!=0){
		int M = R*(C-1)+C*(R-1);
		int m;
		if(M%4==1) m = (R/2-1)*(C/2)+(R/2)*(C/2-1);
		else m = (R/2-1)*(C/2-1)+(R/2)*(C/2);
		//cout<<M<<m;
		if(A-N<=m) cout<<M-(A-N)*4<<endl;
		else cout<<M-m*4-(A-N-m)*3<<endl;
	}
	return;
}

int main(){
	int T;
	freopen("B-small-attempt1.in.txt","r",stdin);
	freopen("out1","w",stdout);
	cin>>T;

	for(int t=0; t<T; t++){
		printf("Case #%d: ",t+1);
		solve();
	}
	return 0;
}