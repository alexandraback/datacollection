#include<bits/stdc++.h>

using namespace std;

#define pid pair<int, char>
#define mp make_pair
#define fi first
#define se second

int main(){
	freopen("out.txt","w",stdout);
	int tc = 0;
	int t;
	scanf("%d",&t);
	while(t--){
		
		int n;
		scanf("%d",&n);
		
		priority_queue<pid> pq;
		int tot = 0;
		
		for(int i = 0 ; i < n; i++){
			int jum;
			scanf("%d",&jum);
			pq.push(mp(jum,i));
			tot+=jum;
		}
		printf("Case #%d: ",++tc);
		while(tot){
			if(tot==3){
				pid tmp = pq.top(); pq.pop();
				char fir = tmp.se; tmp.fi--; tot--;
				if(tmp.fi!=0)pq.push(tmp);
				printf("%c ",fir+'A');
				continue;
			}
			pid tmp = pq.top(); pq.pop();
			char fir = tmp.se; tmp.fi--; tot--;
			if(tmp.fi!=0)pq.push(tmp);
			if(tot==0){
				printf("%c",fir+'A');
				break;
			}
			tmp = pq.top(); pq.pop();
			char sec = tmp.se; tmp.fi--; tot--;
			if(tmp.fi!=0)pq.push(tmp);
			printf("%c%c",fir+'A',sec+'A');
			if(tot!=0) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
