#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100100 ;

int N,T;
int m;
int ar[MAXN];

int main(){
	
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	cin >> T;
	
	for(int test=1;test<=T;test++){
	
		cin >> N;
		m=0;
		for(int i=1;i<=N;i++){
		
			cin >> ar[i];
	
			if(i>1) m=max(m,ar[i-1]-ar[i]);
		}
		
		int res1=0;
		
		for(int i=2;i<=N;i++)
			if(ar[i]<ar[i-1])
				res1+=ar[i-1]-ar[i];
			
		int res2=0;	
			
		for(int i=1;i<N;i++)	res2+=min(m,ar[i]);
		
		printf("Case #%d: %d %d\n",test,res1,res2);
	}
	cin>>N;
	return 0;
}