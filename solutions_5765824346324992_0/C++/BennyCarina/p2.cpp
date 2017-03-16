#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;

#define d_pi 57.2957795
#define LL __int64
#define LarN 100000

template<class T> inline void ReMin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ReMax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}

int B, N, M[1005];
LL buf[1005];
int maxIdx;

LL arrange(LL t){
	LL bound = LL(M[maxIdx])*t;
	for(int i = 1; i <= B; i ++){
		buf[i] = bound/M[i];
	}
	for(int i = 1; i <= B; i ++){
		if(buf[i]*M[i] < bound)buf[i] ++;
	}

	LL ret = 0;
	for(int i = 1; i <= B; i ++){
		ret += buf[i];
	}
	return ret;
}


void solve(){
	scanf("%d %d", &B, &N);
	for(int i = 1;i <= B; i ++){
		scanf("%d", &M[i]);
	}
	maxIdx = 1;
	for(int i = 1; i <= B; i ++){
		if(M[i] > M[maxIdx]){
			maxIdx = i;
		}
	}

	LL left = 0, right = N, mid;
	
	while(right>left){
		mid = (left + right + 1)/2;
		if(arrange(mid) < LL(N)){
			left = mid;
		}
		else{
			right = mid-1;
		}
	}

	LL acc = arrange(left);
	//LL acc = 0;
	//for(int i = 1; i <= B; i ++)buf[i] = 0;
	
	priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>> > PQ;
	for(int i = 1; i <= B; i ++){
		buf[i] = buf[i]*M[i];
		PQ.push(make_pair(buf[i], i));
	}
	pair<LL, int> cur;
	for(LL i = acc+1; i <= N-1; i ++){
		cur = PQ.top();
		int idx = cur.second;
		PQ.pop();
		buf[idx] += M[idx];
		PQ.push(make_pair(buf[idx], idx));
	}

	cur = PQ.top();
	int ans = cur.second;

	printf("%d\n", ans);
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