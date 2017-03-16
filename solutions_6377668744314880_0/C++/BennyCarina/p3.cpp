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

bool sig[20];

double pos[20][2];
int anses[20];
int N;

bool check(int cur, int edge){
	for(int i = 0; i < N; i ++){
		if(!sig[i] || i == cur)continue;
	
		double x1 = pos[edge][0] - pos[cur][0];
		double y1 = pos[edge][1] - pos[cur][1];
		double x2 = pos[i][0] - pos[cur][0];
		double y2 = pos[i][1] - pos[cur][1];

		if(x1*y2 - x2*y1 < 0)return false;
	}
	return true;
}

bool check(int cur){
	int acc = 0;
	for(int i = 0; i < N; i ++){
		if(sig[i])acc ++;
	}
	if(acc < 4)return true;

	for(int i = 0; i < N; i ++){
		if(!sig[i] || i == cur)continue;
		if(check(cur, i))return true;
	}
	return false;
}

void solve(){
	scanf("%d", &N);
	for(int i = 0; i < N; i ++){
		scanf("%lf %lf", &pos[i][0], &pos[i][1]);
	}
	int B = 1<<N;

	if(N < 4){
		for(int i = 0; i < N; i ++){
			printf("0\n");
		}
		return;
	}

	for(int i = 0; i < N; i ++)anses[i] = N-1;
	for(int b = 0; b < B; b ++){
		for(int i = 0; i < N; i ++)sig[i] = false;
		int idx = 0;
		int acc = 0;
		int bb = b;
	
		while(bb>0){
			if(bb%2 == 1){
				sig[idx] = true;
				acc ++;
			}
			idx ++;
			bb >>= 1;
		}
		acc = N - acc;
		for(int i = 0; i < N; i ++){
			
			if(sig[i] && check(i)){
				ReMin(anses[i], acc);
			}
		}
	}

	for(int i = 0; i < N; i ++){
		printf("%d\n", anses[i]);
	}
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T_case;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		printf("Case #%d:\n",i_case);
		solve();
	}
	return 0;
}