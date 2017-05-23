#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class CodeJam{
	public:
		int run(){
			init();
			if(check()){
				printf("Fegla Won\n");
				return 0;
			}
			int res=calculate();
			printf("%d\n",res);
		}
		void init(){
			scanf("%d",&n);
			for(int i=0;i<n;i++) cin>>ins[i];
			memset(len,0,sizeof(len));
		}
		bool check(){
			string temp = "";
			m=0;
			len[0][0]=0;
			int j=0;
			while(j<ins[0].length()){
				int k=j;
				while(j<ins[0].length() && ins[0][j]==ins[0][k]) ++j;
				temp += ins[0][k];
				len[0][++m]=j;
			}
			target = temp;
			for(int i=1;i<n;++i){
				len[i][0]=0; 
				temp = "";
				int ll=0;
				int j=0;
				while(j<ins[i].length()){
					int k=j;
					while(j<ins[i].length() && ins[i][j]==ins[i][k]) ++j;
					temp += ins[i][k];
					len[i][++ll]=j;
				}
				if(ll != m || temp != target) return true;
			}
			return false;
		}
	int calculate(){
		for(int j=0;j<n;j++) for(int i=m;i>0;--i)  len[j][i]-=len[j][i-1];
		//for(int j=0;j<n;j++) for(int i=0;i<=m;i++)  printf(" %d ",len[j][i]);
		int midl = (n-1)>>1,midr;
		if(n%2) midr = midl;
		else midr=midl+1;
		int ll,rr,resl=0,resr=0;
		for(int i=1;i<=m;i++){
			vector<int> map;
			for(int j=0;j<n;j++) map.push_back(len[j][i]);
			sort(map.begin(),map.end());
			ll = map[midl],rr=map[midr];
			for(int j=0;j<n;j++){
				resl += abs(map[j]-ll);
				resr += abs(map[j]-rr);
			}
		}
		return min(resr,resl);
	}
	private:
		int n,m,len[101][101];
		string ins[101],target;
};
int main(){
	freopen("1.txt","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int __=1;__<=T;++__){
		printf("Case #%d: ",__);
		CodeJam test;
		test.run();
	}
	return 0;
}


