#include<bits/stdc++.h>

using namespace std;

int T,N,arr[30],tot;

struct mycomparison
{
  bool operator() (pair<int,int> a,pair<int,int> b)
  {
    return a.first<b.first;
  }
};

priority_queue<pair<int,int>,vector<pair<int,int> >,mycomparison>pq;

int main(){
int max1,max2,num1,num2;

	freopen("senate.in","r",stdin);
	freopen("senate.out","w",stdout);	

	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&N);
		memset(arr,0,sizeof(arr));
		for(int j=1;j<=N;j++) scanf("%d",&arr[j]);
		tot=0;
		for(int j=1;j<=N;j++) tot+=arr[j];
		for(int j=1;j<=N;j++) pq.push(make_pair(arr[j],j));
		printf("Case #%d:",i);
		while (tot>0){
			max1=pq.top().first; num1=pq.top().second; pq.pop(); 
			if (pq.empty()) {
				printf(" %c",num1+64); tot--;
			}
			else {
				if (pq.top().first*2>=tot){
					max2=pq.top().first; num2=pq.top().second; pq.pop();
					printf(" %c%c",num1+64,num2+64); tot-=2;
					if (max1>1) pq.push(make_pair(max1-1,num1));
					if (max2>1) pq.push(make_pair(max2-1,num2));
				}
				else {
					printf(" %c",num1+64); tot--; 
					if (max1>1) pq.push(make_pair(max1-1,num1));
				}
			}
		}
		printf("\n");	
	}
	return 0;
}
