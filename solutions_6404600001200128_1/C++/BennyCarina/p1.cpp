#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<set>
using namespace std;

#define d_pi 57.2957795
#define LL __int64
#define LarN 100000

template<class T> inline void ReMin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ReMax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}

int M[1005];
int N;
void solve(){
	scanf("%d", &N);
	for(int i = 0; i < N; i ++){
		scanf("%d", &M[i]);
	}

	int x, y;
	x = 0;
	for(int i = 0; i < N-1; i ++){
		if(M[i] > M[i+1]) x += M[i] - M[i+1];
	}

	y = 0;
	int maxD = 0;
	for(int i = 0; i < N-1; i ++){
		if(M[i] > M[i+1]) ReMax(maxD, M[i] - M[i+1]);
	}

	for(int i = 0; i < N-1; i ++){
		y += min(M[i], maxD);
	}

	printf("%d %d\n", x, y);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T_case;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		printf("Case #%d: ",i_case);
		solve();
	}
	
	return 0;
}