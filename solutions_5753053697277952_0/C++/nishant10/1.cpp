#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

#define f first
#define s second
#define pb push_back

using namespace std;

typedef pair<int,int> pr;
typedef long long ll;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);



int main() {
	int P[1030],cnt,i,n,mxindex,mx,tc,t;
	freopen("input1.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	tc = 0;
	while(t--) {
		cin>>n;
		cnt = 0;
		for(i = 0;i < n;i++) {
			cin>>P[i];
			cnt = cnt + P[i];
		}
		cout<<"Case #"<<++tc<<": ";
		if(n == 2) {
			while(P[0] > 0) {
				cout<<"AB"<<" ";
				P[0]--;
			}
			cout<<endl;
			continue;
		}
		while(cnt > 2) {
			mx = 0;
			for(i = 0;i < n;i++) {
				if(P[i] >= mx) {
					mxindex = i;
					mx = P[i];
				}			
			}
			P[mxindex]--;
			cnt--;
			cout<<(char)(mxindex + 'A')<<" ";					
		}
		for(i = 0;i < n;i++) {
			if(P[i] > 0)
				cout<<(char)(i + 'A');
		}
		cout<<endl;
	}
	return 0;
}
