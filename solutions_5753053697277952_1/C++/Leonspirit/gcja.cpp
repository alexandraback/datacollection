#include <bits/stdc++.h>

#define mp make_pair
#define ft first
#define sc second

using namespace std;

int main(){
	
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int teskes;
	scanf("%d",&teskes);
	
	for(int tc=1;tc<=teskes;tc++){
		
		priority_queue<pair<int,int> >pq;
		int n;
		scanf("%d",&n);
		int total=0;
		
		for(int x=0;x<n;x++){
			int now;
			scanf("%d",&now);
			total+=now;
			
			if(now!=0)pq.push(mp(now,x));
		}
		
		printf("Case #%d:",tc);
		while(!pq.empty()){
			pair<int,int>now = pq.top(); pq.pop();
			
			if(total==2){
				pair<int,int>secs = pq.top(); pq.pop();
				printf(" %c%c",now.sc+'A',secs.sc+'A');
				break;
			}
			
			
			if(pq.size()==1){
				pair<int,int>secs = pq.top(); pq.pop();
				//cout<<"fukyu "<<secs.ft<<" "<<now.ft<<endl;
				if(now.ft == secs.ft){
					printf(" %c%c",now.sc+'A',secs.sc+'A');
					secs.ft--;
					now.ft--;
					total-=2;
					pq.push(secs);
					pq.push(now);
					continue;
				}
			}
			
			total--;
			now.ft--;
			printf(" %c",now.sc+'A');
			pq.push(now);
		}
		printf("\n");
	}
	return 0;
}
