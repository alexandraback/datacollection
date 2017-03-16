#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <math.h> 
#include <algorithm> 
#include <stdio.h> 
using namespace std;


#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<int>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i<b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())

void judge(){
	int  a;
	scanf("%d",&a);	
	vector<string> ma(a);
	
	REP(i,a){
		cin>>ma[i];
	}
	vector<string> ids=ma;
	REP(i,a){
		ids[i].erase(unique(ALL(ids[i])),ids[i].end());
	}
	FORI(i,1,a){
		if(ids[i]!=ids[i-1]){
			cout<<"Fegla Won";
			return ;
		}
	}
	int ans=0;
	vector<int> places(a,0);
	REP(i,ids[0].size()){
		vector<int> tmp;
		int sum=0,sel=0;
		REP(j,a){
			int k=places[j],t=0;
			while(k<ma[j].size()&&ma[j][k]==ids[0][i]){
				t++;k++;
			}
			places[j]=k;
			tmp.push_back(t);
			sum+=t;
		}
		sort(ALL(tmp));
		sel=tmp[a/2];
		REP(j,a/2){
			ans+=sel-tmp[j];
		}
		FORI(j,a/2+1,a){
			ans+=tmp[j]-sel;
		}
	}
	cout<<ans;
	return;


}
int main(){
	int t;
	scanf("%d",&t);
	REP(tt,t){
		cerr<<tt<<endl;
		printf("Case #%d: ",tt+1);
		judge();
		
		printf("\n");
	}




	return 1;



}