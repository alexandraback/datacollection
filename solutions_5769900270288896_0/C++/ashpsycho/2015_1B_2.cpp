#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,r,c,x,y,m;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>r>>c>>n;
		int arr[r][c];
		m=10000000;
		if(n>(((r*c)+1)/2)){
			for(i=0;i<(1<<(r*c));i++){
				if(__builtin_popcount(i)==n){
					for(x=i,j=0;j<r;j++)
						for(k=0;k<c;k++){
							arr[j][k]=x%2;
							x/=2;
						}
					for(y=0,j=0;j<r;j++)
						for(k=0;k<c;k++){
							if(j!=(r-1)&&arr[j][k]==1&&arr[j+1][k]==1)y++;
							if(k!=(c-1)&&arr[j][k]==1&&arr[j][k+1]==1)y++;
						}
					m=min(m,y);
				}
			}
		}
		else m=0;
		cout<<"Case #"<<(te+1)<<": "<<m<<"\n";
	}
}