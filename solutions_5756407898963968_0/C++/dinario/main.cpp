#include <iostream>
#include <fstream>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;
#define re return
#define ll  long long

const ll MOD=1E9+7;


int main(){
	ifstream cin("input.txt");
	ofstream cout("out.txt");

	ll i,j,n,k,T,t;
	cin>>T;
	for(t=0;t<T;++t){
		int r1,r2;
		int used[20];memset(&used,0,20*sizeof(int));
		cin>>r1;
		for(i=0;i<4;++i)
			for(j=0;j<4;++j){
				cin>>k;
				if(i+1==r1)used[k]+=1;
			}
		cin>>r2;
		for(i=0;i<4;++i)
			for(j=0;j<4;++j){
				cin>>k;
				if(i+1==r2)used[k]+=1;
			}
		int res=0,cnt=0;
		for(i=1;i<17;++i)if(used[i]==2){
			res=i;cnt++;
		}
		cout<<"Case #"<<t+1<<": ";
		if(cnt==0)cout<<"Volunteer cheated!"<<endl;
		if(cnt==1)cout<<res<<endl;
		if(cnt>1)cout<<"Bad magician!"<<endl;
	}
	re 0;
}