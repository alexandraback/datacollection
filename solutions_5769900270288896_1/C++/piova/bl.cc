#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <set>

#define mk make_pair
#define pb push_back
typedef  long long  LL;

using namespace std;
int N,R,C;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int g[10001][10001];

int calc(int x,int y){
	int px,py,tmp=0;
	for(int i=0;i<4;i++){
		px=x+dx[i];
		py=y+dy[i];
		if(px>0 && px<=R && py>0 && py<=C)
			tmp++;
	}
	return tmp;
}
vector<int> sum1;

vector<int> sum2;

int main(){
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		printf("Case #%d: ",cas);
		scanf("%d%d%d",&R,&C,&N);
		sum1.clear();
		sum2.clear();
		int cnt,ans1,ans2,res;
		int black=0,white=0;
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++){
				if(!((i+j) & 1)){
					black++;
					res = calc(i,j);
					sum2.pb(res);
				}
				else{
					white++;
					res = calc(i,j);
					sum1.pb(res);
				}
			}
		sort(sum1.begin(),sum1.end());
		sort(sum2.begin(),sum2.end());
		
		ans1=0,ans2=0;
		for(int i=0;i<N-black;i++)
			ans1+=sum1[i];
		for(int i=0;i<N-white;i++)
			ans2+=sum2[i];
	
		printf("%d\n",ans1<ans2?ans1:ans2);
	}
	return 0;
}