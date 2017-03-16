#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ar[100][100];

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		memset(ar,0,sizeof(ar));
		int N; scanf("%d",&N);
		int an=0;
		string s; cin >> s;
		string Ans=""; Ans+=s[0];
		int Len = s.length();
		bool Same=true;
		for(int i=1; i<Len; ++i){
			if(s[i]==s[i-1]) ++ar[an][0];
			else{ Ans+=s[i]; ++an; }
		}
		int AnsLen=Ans.length();
		for(int i=1; i<N; ++i){
			cin >> s; Len=s.length();
			if(s[0]!=Ans[0]){Same=false;}
			if(!Same) continue;
			an=0;
			for(int j=1; j<Len; ++j){
				if(s[j]==s[j-1]) ++ar[an][i];
				else if(Ans[++an]!=s[j]){Same=false; break;}
			}
			if(an!=AnsLen-1) Same=false;
		}
//		for(int i=0; i<Len; ++i){
//			for(int j=0; j<N; ++j)
//				printf("%d ",ar[j][i]);
//			printf("\n");
//		}
		if(!Same){printf("Case #%d: Fegla Won\n",Case);continue;}
		Len=Ans.length();
		int ans=0;
		for(int i=0; i<Len; ++i){
			sort(ar[i],ar[i]+N);
			int tot=0,mid=ar[i][N/2];
			for(int j=0; j<N; ++j){
				int tmp=ar[i][j]-mid;
				if(tmp<0) tmp*=(-1);
				tot+=tmp;
			}
			ans+=tot;
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
