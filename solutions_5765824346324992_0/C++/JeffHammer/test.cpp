#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define mp(a,b) make_pair((a),(b))
#define MS( a,n ) memset( a,0,sizeof(a)*n)
#define MSV( a,v ) memset( a,v,sizeof(a))
typedef long long ll;
typedef pair<int,int> pii;
#define ALL(C) (C).begin(), (C).end()
#define forIter(I,C) for(auto I=(C).begin(); I!=(C).end(); ++I)
#define forNF(I,S,C) for(int I=(S); I<int(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef vector<pii> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;

u64 gcd(u64 a, u64 b) { u64 t; if(a < b) { t = a; a = b; b = t; } if(b == 0) return a; return gcd(b, a % b); }
u64 lcm(u64 a, u64 b) { return a * b / gcd(a, b); }

u64 lcmall(vector<int> vec){
	if(vec.size()==1){return vec[0];}
	u64 ans = lcm(vec[0],vec[1]);
	for(int i=2;i<vec.size();i++){
		ans = lcm(ans,vec[i]);
	}
	return ans;
}

int solve(VI vec, int N){
	u64 lcm = lcmall(vec);
	int circle  = 0;
	forEach(i,vec){
		circle += lcm/vec[i];
	}
	N = N % circle;
	if(N == 0) {N=circle;}
	int ans = 0;
	VI assign;
	forN(i,vec.size()){
		assign.push_back(0);
	}
	int minnum = INT_MAX;
	while(N){
		forEach(i,assign){
			if(assign[i]==0){
				assign[i]+=vec[i];
				N--;
				if(!N){return i;}
			}
			minnum = min(assign[i],minnum);
		}
		forEach(i,assign){
			assign[i]-=minnum;
		}
	}

}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TC, T;
	cin>>TC;
	for (T = 1; T <= TC; T++){
		int B,N;
		cin>>B>>N;;
		vector<int> vec(B);
		forN(i,B){
			cin>>vec[i];
		}
		printf("Case #%d: ", T);
		cout<<solve(vec,N) + 1<<endl;

	}
}