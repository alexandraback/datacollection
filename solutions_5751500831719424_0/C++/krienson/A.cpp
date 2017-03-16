#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define FOR(i,x,y) for(int i=(int)x; i<(int)y; i++)
#define RFOR(i,x,y) for(int i=(int)x; i>(int)y; i--)
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define IN(a,pos,c) insert(a.begin()+pos,1,c)
#define DEL(a,pos,cant) erase(a.begin()+pos,cant)
#define INF 1000000

int main(){
	int kases; cin>>kases;
	for(int kase=1;kase<=kases;kase++){
		int N; cin>>N;
		vector<vector<pair<char, int> > > vp;
		string s;
		for(int i=0;i<N;i++){
			cin>>s;
			vector<pair<char, int> > v;
			int count = 1;
			char c = s[0];
			for(int j=1;j<int(s.length());j++){
				if(s[j] == c){
					count++;
				}
				else{
					v.PB(MP(c,count));
					c = s[j]; count = 1;
				}
			}
			v.PB(MP(c,count));
			vp.PB(v);
		} //cout<<"FINISHED"<<endl;
		bool ok = true;
		//for(int i=0;i<int(vp.SZ);i++){ for(int j=0;j<int(vp[i].SZ);j++) cout<<vp[i][j].X<<" "<<vp[i][j].Y<<endl; cout<<endl;}
		for(int i=1;ok && i<int(vp.SZ);i++){
			
			if(vp[i-1].SZ != vp[i].SZ){
				ok = false;
			}
			else{
				for(int j=0;j<int(vp[i].SZ);j++){ 
					if(vp[i][j].X != vp[i-1][j].X){ ok=false; break;}
				}
			}
		}
		if(!ok){ cout<<"Case #"<<kase<<": Fegla Won"<<endl; continue;}
		int tam = int(vp[0].SZ);
		int res = 0;
		for(int j = 0; j < tam; j++){
			//chose one size
			int br = 1000000000;
			for(int k = 1; k < 101;k++){
				int current_res = 0;
				for(int i=0;i<int(vp.SZ);i++){
					current_res += abs(vp[i][j].Y - k);
				}
				br = min(br, current_res);
			}
			res += br;
		}
		cout<<"Case #"<<kase<<": "<<res<<endl;		
	}
}
