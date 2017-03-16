/*
***************************************************************************************************************

							Author : Yash Sadhwani

**************************************************************************************************************
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define mod 1000000007

	
#define MAXN 200110
#define SQRT 330
#define ls (node<<1)
#define rs ((node<<1)+1)
#define ii pair<int,int>
#define F first
#define S second

ll modpow(ll base, ll exponent,ll modulus){
	if(base==0&&exponent==0)return 0;
	ll result = 1;
	while (exponent > 0){
		if (exponent % 2 == 1)
		    result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}


int N, P[MAXN], tot;

inline void ReadInput(void){
	si(N); for(int i = 1; i <= N; i++){ si(P[i]); tot += P[i];}
}

inline void solve(int t){
	printf("Case #%d: ", t);
	while(tot > 0){
		bool flag = false;
		for(int i = 1; i <= N; i++){
			tot--; P[i]--;
			if(P[i] < 0){
				tot++; P[i]++;
				continue;
			}
			bool x = false;
			for(int j = 1; j <= N; j++){
				if(P[j] * 2 > tot) x = true;
			}
			if(!x){
				char c = i - 1 + 'A';
				printf("%c ", c);
				flag = true;
				break;
			}
			tot++; P[i]++;
		}
		if(flag) continue;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				tot -= 2; P[i]--; P[j]--;
				if(P[i] < 0 or P[j] < 0){
					tot += 2; P[i]++; P[j]++;
					continue;
				}
				bool x = false;
				for(int k = 1; k <= N; k++){
					if(P[k] * 2 > tot) x = true;
				}
				if(!x){
					char c = i - 1 + 'A', d = j - 1 + 'A';
					printf("%c%c ", c, d);	
					flag = true;
					break;
				}
				tot += 2; P[i]++; P[j]++;
			}
			if(flag) break;
		}
	}
	printf("\n");
}

inline void Refresh(void){
	tot = 0;
}

int main()
{	
	//ios_base::sync_with_stdio(false);
	int t; si(t);
	int g = 1;
	while(t--){
		ReadInput();
		solve(g);
		Refresh();
		g++;
	}
    return 0;
}

// U COME AT THE KING, BETTER NOT MISS !!!