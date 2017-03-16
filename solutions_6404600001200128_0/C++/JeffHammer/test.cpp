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

int mehtod1(vector<int> vec){
	
	int ans = 0;

	for(int i=0;i<vec.size()-1;i++){
		if(vec[i]>vec[i+1]){
			ans += (vec[i]-vec[i+1]);
		}
	}
	return ans;
}

int method2(vector<int> vec){
	int ans = 0;
	int gap =0;
	for(int i=0;i<vec.size()-1;i++){
		if(vec[i]>vec[i+1]){
			gap =  max((vec[i]-vec[i+1]),gap);
		}
	}
	for(int i=0;i<vec.size()-1;i++){
		ans += min(gap,vec[i]);
	}
	return ans;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TC, T;
	cin>>TC;
	for (T = 1; T <= TC; T++){
		int N;
		cin>>N;
		vector<int> vec(N);
		forN(i,N){
			cin>>vec[i];
		}
		printf("Case #%d: ", T);
		cout<<mehtod1(vec)<<" "<<method2(vec)<<endl;

	}
}