// __________ AUTHOR INFO __________
// Name/    Khaled Alam
// Email/   khaledalam.net@gmail.com
// Insta/   @MrKhaledAlam
// Twitter/ @Mr_KhaledAlam
// Website/ KhaledAlam.net
//__________________________________


#include <bits/stdc++.h>

/*
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
*/

//____________________
using namespace std;

#define UI  unsigned int
#define LL  long long
#define ULL unsigned long long
#define V   vector
#define oo   I (1e9)
#define MOD  I (1e9+7)
#define PI  3.14159265358979323846;
#define SZ(X) (int)X.size()
#define FI first
#define SE second
#define PB push_back
#define PF push_front
#define MP make_pair
#define ODD(n)  (n&1)
#define ONES(N) __builtin_popcount((LL)N)
#define ALL(C)  C.begin(), C.end()
#define rALL(C) C.rbegin(), C.rend()
#define rSORT(C) sort(ALL(C), std::greater<LL>())
#define FOR(V,A,Z,P)   for(LL V=A; V<Z;  V+=P)
#define FORe(V,A,Z,P)  for(LL V=A; V<=Z; V+=P)
#define rFOR(V,A,Z,P)  for(LL V=A; V>Z;  V-=P)
#define rFORe(V,A,Z,P) for(LL V=A; V>=Z; V-=P)
#define IOS ios_base::sync_with_stdio(0)
#define SET(A,V) memset(A,(typeof(V))V,sizeof(A))
#define iFILE(N) freopen(#N, "r", stdin)
#define oFILE(N) freopen(#N, "w", stdout)
#define TM cerr<<"Time elapsed: "<<clock()<<" ms\n";
//#define MX
//I vis[100];

typedef long long int ll;

ll b,m;
ll ans[50][50];
ll dp[50];

void init()
{
	for(ll i=0;i<50;i++)
	{
		for(ll j=0;j<50;j++)
			ans[i][j]=0;
		dp[i]=0;
	}

}

void build()
{
	ll i,j;
	for(i=b;i>=0;i--)
	{
		for(j=i+1;j<=b;j++)
		{
			if(m>=dp[j]+dp[i])
			{
				ans[i][j]=1;
				dp[i]+=dp[j];

				if(dp[i]==m)
				break;

			}
		}
	}

}


int main(){
iFILE(input.txt);
oFILE(output.txt);

	int freq[501][27], t, m;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		int n, a;
		m=0;
		for(int j=0; j<=500; j++) for(int k=0; k<=26; k++) freq[j][k]=0;
		scanf("%d", &n);
		for(int j=1; j<=n; j++){
			scanf("%d", &a);
			for(int k=1; k<=a; k++){
				m=max(m, a);
				freq[k][0]++;
				freq[k][freq[k][0]]=j;
			}
		}
		printf("Case #%d: ", i);

		for(int j=m; j>=1; j--){
			if(freq[j][0]%2==1){
				printf("%c", freq[j][freq[j][0]]+'A'-1);
				freq[j][0]--;
				if(j==1 && freq[j][0]==0) printf("\n");
				else printf(" ");
			}
			while(freq[j][0]!=0){
				printf("%c%c", freq[j][freq[j][0]-1]+'A'-1, freq[j][freq[j][0]]+'A'-1);
				freq[j][0]-=2;
				if(j==1 && freq[j][0]==0) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
