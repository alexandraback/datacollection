#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

struct letter{
	letter(){}
	letter(int x,char c):x(x),c(c){}
	int x;
	char c;
};

vector<letter> tot[105];
vector<int> p;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,N;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		char s[105]="";
		bool ch=true;
		printf("Case #%d: ",t);
		scanf("%d",&N);
		for(int i=1;i<=N;i++){
			ch=true;
			tot[i].clear();
			scanf("%s",s);
			tot[i].push_back(letter(1,s[0]));
			for(int j=1;j<strlen(s);j++){
				if(tot[i].back().c == s[j])tot[i].back().x++;
				else tot[i].push_back(letter(1,s[j]));
			}
		}
		for(int i=2;i<=N;i++){
			if(tot[i].size() != tot[1].size()){
				ch = false;
				break;
			}
		}
		int ans=0;
		if(ch){
			for(int j=0;j<tot[1].size();j++){
				for(int i=2;i<=N;i++){
					if(tot[i][j].c != tot[1][j].c)ch=false;
				}
				p.clear();
				for(int i=1;i<=N;i++){
					p.push_back(tot[i][j].x);
				}
				sort(p.begin(),p.end());
				for(int i=1;i<=N;i++){
					ans += abs(tot[i][j].x - p[p.size()/2]);
				}
			}
		}
		if(!ch)printf("Fegla Won\n");
		else printf("%d\n",ans);
	}
}
