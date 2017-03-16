#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <utility>
vector < pair <int, char> > a[1000];
pair <int, char> crtemp;
int main(){
	int T,i1;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	cin>>T;
	for(i1=0;i1<T;i1++){
//***********************************************************
	int n,i,j,len,strcount=0,res=0,mintr,k;
	char temp[10000];
	bool resflag=true;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>temp;
		len=strlen(temp);
		int crcount=1;
		for(j=1;j<=len;j++){
			if(temp[j]!=temp[j-1]){
				crtemp.first=crcount;
				crtemp.second=temp[j-1];
				crcount=0;
				a[strcount].push_back(crtemp);
			}
			crcount++;
		}
		strcount++;
	}

	for(i=1;i<n;i++){
		if(a[i].size()!=a[i-1].size()){
			resflag=false;
			break;
		}
		len=a[i].size();
		for(j=0;j<len;j++){
			if(a[i][j].second!=a[i-1][j].second){
				resflag=false;
				break;
			}	
		}
	}
	if(resflag==0)
		cout<<"Case #"<<i1+1<<": Fegla Won"<<endl;
	if(resflag){
	int b[101][101],tempsum=0;
	len=a[0].size();
	for(i=0;i<len;i++){
		mintr=1000000000;
		for(j=0;j<n;j++){
			tempsum=0;
			for(k=0;k<n;k++){
				tempsum+=(abs(a[j][i].first-a[k][i].first));
			}
			if(tempsum<mintr)
				mintr=tempsum;
			tempsum=0;
		}
		res+=mintr;		
	}
	cout<<"Case #"<<i1+1<<": "<<res<<endl;
	}
	for(i=0;i<n;i++)
		a[i].clear();
//***********************************************************
}



}