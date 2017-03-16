#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#define SQ(a) ((a)*(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483647;
const int mod = 1000000007;


int main(){
	int TT;
	scanf("%d",&TT);
	for(int T=1;T<=TT;T++){
		printf("Case #%d: ",T);
		int n;
		scanf("%d",&n);
		int a[30];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int mx=0;
		while(1){
			mx=0;
			for(int i=0;i<n;i++){
				mx=max(a[i],mx);
			}
			if(mx==0)break;
			int t=0;
			for(int i=0;i<n;i++){
				if(a[i]==mx)t++;
			}
			char c;
			int x=0;
			for(int i=0;i<n;i++){
				if(a[i]==mx){
					if(t%2==1){printf("%c ",'A'+i);a[i]--;t--;}
					else{
						a[i]--;
						if(x==1){printf("%c%c ",'A'+i,c);x=0;t-=2;}
						else {c='A'+i;x=1;}

					}
				}
			}
		}

		printf("\n");
	}
}