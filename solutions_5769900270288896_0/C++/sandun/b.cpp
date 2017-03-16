#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int run(int R,int C,int N){
	set<PII>hs[6];
	int del=R*C-N;
	for(int i=1;i<=R;++i){
		for(int j=1;j<=C;++j){
			int k=4;
			if(i==1){
				--k;
			}
			if(i==R){
				--k;
			}
			if(j==1){
				--k;
			}
			if(j==C){
				--k;
			}
			hs[k].insert(PII(i,j));
		}
	}
	int ans=R*C*2-R-C;
	  
	while(del>0){
		for(int i=4;i>=0;--i){
			if(!hs[i].empty()){
				PII tv=*hs[i].begin();
				hs[i].erase(tv);
				--del;
				ans-=i;
				int x=tv.first;
				int y=tv.second;
				for(int k=0;k<4;++k){
					int nx=x+dx[k];
					int ny=y+dy[k];
					PII pv(nx,ny);
					
					for(int j=4;j>0;--j){
						if(hs[j].count(pv)){
							hs[j-1].insert(pv);
							hs[j].erase(pv);
						}
					}
				}
				break;

			}
		}
	}
	
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10)<<endl;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	//freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	for(int cas=1;cas<=T;++cas){
		int R,C,N;
		cin>>R>>C>>N;
		cout<<"Case #"<<cas<<": "<<run(R,C,N)<<endl;
		cerr<<run(R,C,N)<<endl;
	}
	return 0;
}

