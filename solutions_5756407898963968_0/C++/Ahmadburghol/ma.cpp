#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <memory.h>
#include <algorithm>
using namespace std;
const int N=4;

int t,row;
int g[N][N];
int arr[17];
vector<int> v;

int main(){
 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		memset(arr,0,sizeof(arr));
		v.clear();
		scanf("%d",&row);
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				scanf("%d",&g[i][j]);
		for(int j=0;j<N;++j)
			++arr[g[row-1][j]];
		scanf("%d",&row);
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				scanf("%d",&g[i][j]);
		for(int j=0;j<N;++j)
			++arr[g[row-1][j]];
		for(int i=0;i<17;++i)
			if(arr[i]>=2)
				v.push_back(i);
		printf("Case #%d: ",k);
		if(v.size()==1)
			printf("%d\n",v[0]);
		else if(v.size()==0)
			puts("Volunteer cheated!");
		else if(v.size()>=2)
			puts("Bad magician!");
	}

	return 0;
} 