#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < b; i++)
#define fre(i,a,b) for(int i = a; i <= b; i++)
#define frd(i,a,b) for(int i = a; i > b; i--)
#define fred(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define SET(a,v) memset(a,v,sizeof a)

#define INF 1e8

typedef long long ll;
typedef pair<int,int> ii;

#define N 1010
int t,n,p;
ii arr[N];

void solve(){

}

int comp(ii b, ii c){
	return b > c;
}

int main(){
	scanf("%d",&t);
	fr(t2,0,t){
		printf("Case #%d: ",t2+1);
		scanf("%d",&n);
		fr(i,0,n) {
			scanf("%d",&p);
			arr[i] = ii(p,i);
		}
		sort(arr,arr+n,comp);
		
		int q = 0;
		//fr(i,0,n) printf("%d ",arr[i].first);
		//puts("");
		
		if (n > 1){
			while (arr[0].first > arr[1].first){
				if (q) printf(" ");
				printf("%c",arr[0].second + 'A');
				arr[0].first--;
				q++;
			}
			
			fr(i,2,n){
				fr(j,0,arr[i].first){
					if (q) printf(" ");
					printf("%c",arr[i].second + 'A');
					q++;
				}
			}
			
			int mini = arr[0].first;
			fr(i,0,mini){
				if (q) printf(" ");
				printf("%c%c",arr[0].second + 'A',arr[1].second + 'A');
				q++;
			}
		} else{
			fr(j,0,arr[0].first){
				if (q) printf(" ");
				printf("%c",arr[0].second + 'A');
				q++;
			}
		}
		
		
		
		puts("");
		
		
		solve();		
	}

	return 0;
}