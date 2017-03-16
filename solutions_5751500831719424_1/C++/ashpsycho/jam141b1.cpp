#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main(){
	int t,te,i,j,k,n,typed,x;
	ifstream f1;
	ofstream f2;
	f1.open("input.txt");
	f2.open("output.txt");
	f1>>t;
	for(te=0;te<t;te++){
		f1>>n;
		string arr[n],brr[n];
		for(i=0;i<n;i++)f1>>arr[i];
		for(i=0;i<n;i++){
			string s="";
			for(j=0;j<arr[i].size();j++){
				s=s+arr[i][j];		
				while((j+1)<(arr[i].size())&&arr[i][j]==arr[i][j+1])j++;		
			}		
			brr[i]=s;
			cout<<brr[i]<<"\n";
		}
		for(i=1;i<n&&brr[i]==brr[0];i++);
		if(i<n){
			f2<<"Case #"<<te+1<<": Fegla Won\n";
			continue;
		}
		int maxc[brr[0].size()],count[n][brr[0].size()];
		for(i=0;i<brr[0].size();i++)maxc[i]=0;
		for(i=0;i<n;i++){
			for(j=k=0;j<brr[0].size();j++){
				x=0;
				while(arr[i][k]==brr[0][j]){
					k++;
					x++;
				}
				if(x>maxc[j])maxc[j]=x;
				count[i][j]=x;
			}
		}
		int ans=0;
		for(i=0;i<brr[0].size();i++){
			int mincount=maxc[i]*n;
			for(j=1;j<=maxc[i];j++){
				x=0;
				for(k=0;k<n;k++){
					x+=(int)abs(count[k][i]-j);
				}
				cout<<i<<" "<<j<<" "<<x<<"\n";
				mincount=min(mincount,x);
			}
			ans+=mincount;
		}
		f2<<"Case #"<<te+1<<": "<<ans<<"\n";
	}
	return 0;
}
