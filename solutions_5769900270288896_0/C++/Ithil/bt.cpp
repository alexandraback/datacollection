#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int R,C;

int main(){
	int cases;
	cin>>cases;
	for(int tc=1;tc<=cases;tc++){
		int u;
		cin>>R>>C>>u;
		string s="";
		for(int i=0;i<R*C;i++){
			s+=".";
		}
		for(int i=0;i<u;i++){
			s[i]='X';
		}
		//cout<<s<<endl;
		sort(s.begin(),s.end());
		int ans=INT_MAX;
		do{
			int pos=0;
			char G[30][30];
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					G[i][j]=s[pos++];
				}
			}		
			int ret=0;
			for(int i=0;i<R;i++){
				for(int j=1;j<C;j++){
					if(G[i][j]=='X'&&G[i][j-1]==G[i][j])ret++;
				}
			}
			for(int i=0;i<C;i++){
				for(int j=1;j<R;j++){
					if(G[j][i]=='X'&&G[j-1][i]==G[j][i])ret++;
				}
			}
			ans=min(ret,ans);
		}while(next_permutation(s.begin(),s.end()));
		cout<<"Case #"<<tc<<": "<<ans<<"\n";
	}
}
