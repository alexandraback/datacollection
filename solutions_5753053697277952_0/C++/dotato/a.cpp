#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
int main(){

	int test,t=0,n,in[27],i,sum;
	priority_queue<pi, vector<pi> > pq;
	
	for( scanf("%d",&test) ; test-- ; putchar(10) ){
		sum=0;
		for(;!pq.empty();pq.pop());
		scanf("%d",&n);
		for( i=0 ; i<n ; i++ ){
			scanf("%d",&in[i]);
			sum+=in[i];
			pq.emplace(in[i],i);
		}
		
		printf("Case #%d:",++t);
		
		for(; pq.top().first ; sum-- ){
			pi temp = pq.top();
			pq.pop();
			
			// 2nd largest party become majority
			if( pq.top().first > (sum-1)/2 ){
				temp.first--;
				pq.push(temp);
				
				printf(" %c",temp.second+'A');
				
				temp = pq.top();
				pq.pop();
				temp.first--;
				pq.push(temp);
				
				putchar(temp.second+'A');
				sum--;
				
			}
			else{
				temp.first--;
				pq.push(temp);
				printf(" %c",temp.second+'A');
			}
		}
	}
	return 0;
}

