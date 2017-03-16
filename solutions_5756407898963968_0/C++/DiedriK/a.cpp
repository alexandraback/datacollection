#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t;
	cin>>t;
	for(int tc=1; tc<=t; tc++){
		int ga[4][4], a, gb[4][4], b;
		cin>>a; a--;
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				cin>>ga[i][j];
		cin>>b; b--;
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				cin>>gb[i][j];
				
		set<int> res;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(ga[a][i]==gb[b][j])
					res.insert(ga[a][i]);
			}
		}
		
		cout<<"Case #"<<tc<<": ";
		if(res.size()==1)
			cout<<*res.begin()<<endl;
		else if(res.size()==0)
			cout<<"Volunteer cheated!"<<endl;
		else
			cout<<"Bad magician!"<<endl;
	}

	return 0;
}
