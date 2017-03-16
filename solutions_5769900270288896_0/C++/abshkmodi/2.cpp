#include<bits/stdc++.h>

using namespace std;

int countbits(int n){
	int ans=0;
	while(n){
		if(n&1)
			ans++;
		n=n>>1;
	}
	return ans;
}

int isvalid(int i,int j,int r,int c){

	if(i>=0 && i<r && j>=0 && j<c)
		return 1;

	return 0;
} 

int dx[2]={1,0};
int dy[2]={0,1};

int unhappy(int r,int c,int x){
	int a[r][c];
	int ans=0;
	memset(a,0,sizeof(a));

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			a[i][j]=x&1;
			x=x>>1;
		}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			for(int k=0;k<2;k++){
				if(a[i][j] && isvalid(i+dx[k],j+dy[k],r,c) && a[i+dx[k]][j+dy[k]])
					ans++;
			}
		}
	}

	return ans;
}
int main(){

	int t;

	cin>>t;

	//cout<<unhappy(2,3,63)<<endl;
	for(int cnt=1;cnt<=t;cnt++){
		
		int ans=9999999;

		int r,c,n;

		cin>>r>>c>>n;

		int upper=1<<(r*c);

		if(n==0){
			cout<<"Case #"<<cnt<<": 0"<<endl;
			continue;
		}

		else{

			for(int i=1;i<upper;i++){
				if(countbits(i)==n){
					ans=min(ans,unhappy(r,c,i));
				}
			}
		}

		cout<<"Case #"<<cnt<<": "<<ans<<endl;
	}

	return 0;
}