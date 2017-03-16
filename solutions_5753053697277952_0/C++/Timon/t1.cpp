#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t=0;t<T;++t){
		int p;
		cin >> p;
		vector<int>q(p);
		vector<pii>res;
		for(int i=0;i<p;++i)cin >> q[i];
		while(1){
			int biggest=-1;
			vector<int>e;
			for(int i=0;i<p;++i){
				if(q[i]>biggest){e.clear();biggest=q[i];}
				if(q[i]==biggest)e.push_back(i);
			}
			if(biggest==0)break;
			if(e.size()!=2){res.push_back({e[0],-1});q[e[0]]--;}
			else{res.push_back({e[0],e[1]});q[e[0]]--;q[e[1]]--;}

		}
		cout << "Case #" << t+1 << ": ";
		for(auto i:res){
			cout << (char)('A'+(char)i.first);
			if(i.second!=-1)
				cout << (char)('A'+i.second);
			cout << " ";
		} 
		cout << "\n";
	}

}
