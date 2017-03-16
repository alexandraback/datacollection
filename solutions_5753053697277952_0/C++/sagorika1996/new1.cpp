// Author : SAGORIKA DAS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iomanip>
#define ll long long
#define F first
#define S second
#define MOD 1000000007
#define inf 1000000006
#define pb push_back
#define MAX 200002
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define CLEAR(a) memset(a,0,sizeof a)
#define pii pair< int , int >
#define piii pair< int , pii >
#define piiii pair< int, piii >
#define fr freopen("input.txt", "r", stdin);
#define fw freopen("output.txt", "w", stdout);
#define pause system("pause");
//#define int long long
using namespace std;
int f[26];

int main()
{
	fr;fw;
	int T,cases=1;
	cin >>T;
	while(T--){
		int n;
		cin >> n;
		priority_queue< pair<int,int> > pq; 
		REP(i,n){
			cin >> f[i];
			pq.push(mp(f[i],i));
		}
		printf("Case #%d: ",cases++);
		while(1){
			if(pq.empty()) break;
		
			int idx = pq.top().S;
			if(pq.top().F == 1){
				if(pq.size()%2){
			     cout<< (char)(idx +'A')<<" ";
			     f[idx]--;
			     pq.pop();
				continue;
				}
			}
			cout<< (char)(idx +'A');
			f[idx]--;
			pq.pop();
			if(f[idx]) pq.push(mp(f[idx],idx));
			idx = pq.top().S;
			cout<<(char)(idx +'A')<<" ";
			f[idx]--;
			pq.pop();
			if(f[idx]) pq.push(mp(f[idx],idx));
		}
		cout<<"\n";

	}

	return 0;
}
