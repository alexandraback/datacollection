# include <bits/stdc++.h>

# define ff first
# define ss second
# define mp(x,y) make_pair(x,y)
# define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

template<typename A, typename B> inline void amax(A &x, B y) {if(x < y) x = y;}
template<typename A, typename B> inline void amin(A &x, B y) {if(!(x < y)) x = y;}

typedef long long lld;

using namespace std;

int n;
int t;
int A[90], sz;
int r, c;
int ans;
int have[90];

int tap(){
	int ret = 0;
	
	for(int i=0; i<sz; i++)
		have[A[i]] = 1;
	
	for(int i=0; i<sz; i++)
		ret += have[A[i]+c];
	
	for(int i=0; i<sz; i++)
		if((A[i]+1) % c != 0)
			ret += have[A[i]+1];
	
	for(int i=0; i<sz; i++)
		have[A[i]] = 0;
	
	amin(ans, ret);
}

int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	scanf("%d",&t);
	
	for(int p=1; p<=t; p++){
		scanf("%d %d %d",&r,&c,&n);
		
		ans = r*c*4;
		
		if(n == 0){
			printf("Case #%d: 0\n",p);
			continue;
		}
		
		int hm = 1<<(r * c);
		
		for(int i=1; i<hm; i++){
			sz = 0;
			
			for(int j=0; j<16; j++)
				if(((1<<j) & i) != 0)
					A[sz++] = j;
			
			if(sz == n)
				tap();
		}
		
		printf("Case #%d: %d\n",p,ans);
	}
}

