#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T>
ll toL(T t){stringstream ss;ss<<t;ll r;ss>>r;return r;}

template <class T>
string toS(T t){stringstream ss;ss<<t;string r;ss>>r;return r;}


int mx[4]= {1,0,-1,0};
int my[4]= {0,1,0,-1};

int contar(vector<vector<int> > & a){
	set<pair<pair<int,int>,pair<int,int> > > vis;
	for(int i=0;i<a.size();i++){
		for(int j=0;j <	a[i].size();j++){
			if(!a[i][j])continue;
			for(int k=0;k<4;k++){
				int tx = i + mx[k];
				int ty = j + my[k];
				//cout<<tx<<" "<<ty<<endl;
				if(tx>=0 && tx < a.size() && ty>=0 && ty <a[i].size() && a[tx][ty]){
				
					vis.insert({{i,j},{tx,ty}});
					vis.insert({{tx,ty},{i,j}});
				}
			}
		}
	}
	return vis.size()/2;
}

void print(vector<vector<int> > & a){
	set<pair<pair<int,int>,pair<int,int> > > vis;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return	;
}

int main(){
	int t,nc=0;cin>>t;
	while(t--){
		int r,c,n;cin>>r>>c>>n;
		
		vector<vector<int> > board(r,vector<int>(c,0));		
		
		int sol = 1000000;
		
		for(int i=0;i<(1<<(r*c))	;i++){
			if(__builtin_popcount(i)!=n)continue;
			//cout<<i<<endl;	
			vector<vector<int> > bt = board;
			int it = 0,jt = 1;
			for(int j=0;j<r*c;j++){
				if((i & (1<<j))!= 0 ){
					//cout<<it<<" "<<jt<<endl;
					bt[it][jt-1] = 1;
				}
				jt++;
				if(jt%(c+1)==0){
					jt=1;it++;
				}
				
			}
			//cout<<bt.size()<<" "<<bt[0].size()<<endl;	
			//print(bt);
			//cout<<"pasa"<<endl;
			sol = min(sol,contar(bt));
		}			
		cout<<"Case #"<<++nc<<": "<<sol<<endl;
	
	}
}
