#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100100 ;

int N,T,B;
int m;
int ar[MAXN];

int main(){
	
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	cin >> T;
	
	for(int test=1;test<=T;test++){
	
		cin >> B >> N ;
	
		for(int i=1;i<=B;i++) scanf(" %d",ar+i);
		
		long long int r;
		
		for(long long int beg=1,end=100000LL*(long long int)N,mid;beg<=end;){
			
			mid=beg+end;
			mid/=2;
			
			long long int t=0;
			for(int i=1;i<=B;i++){
				
				t+=mid/ar[i];
				if(mid%ar[i]) t++;
			}
			
			if(t>=N){r=mid; end=mid-1;}
			else beg=mid+1;
		}
		
		long long int t=0;
		for(int i=1;i<=B;i++){
				
			t+=(r-1)/ar[i];
			if((r-1)%ar[i]) t++;
		}
		
		t=N-t;
		
		for(int i=1;i<=B;i++)
			if(r%ar[i] == 1 || ar[i]==1){
				
				t--;
				if(!t){
					printf("Case #%d: %d\n",test,i); break;
				}
			}
			
		
	}
	
	return 0;
}